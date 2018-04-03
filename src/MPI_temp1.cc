#include "mpi.h"
#include <iostream>
#include <algorithm>
#include <cmath>

#define EPS 1e-3
#define HEIGHT 10
#define WIDTH 10

using namespace std;

//横着按线程数划分块，因为MPI_Sendrec在传递二维数组时，横着相邻的值传递
int main(int argc, char *argv[]) {
    int i, j, k, my_id, np_size, my_size, begin, end, result = 0;

    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_id);
    MPI_Comm_size(MPI_COMM_WORLD, &np_size);

    my_size = HEIGHT / (np_size - 1);
    double BigMatrix[HEIGHT][WIDTH];
    double a[my_size + 2][WIDTH], b[my_size + 2][WIDTH];
    int counter[np_size];

    if (my_id == 0) {
        //0号进程负责给完整数组赋值，分配，以及收集其他进程计算得到的结果
        for (i = 0; i < HEIGHT; i++) {
            for (j = 0; j < WIDTH; j++) {
                BigMatrix[i][j] = 0;
                if (i == 0 || j == 0 || i == (HEIGHT - 1) || j == (WIDTH - 1))
                    BigMatrix[i][j] = static_cast<double>(max(i, j));
            }
        }

        for (k = 1; k < np_size; k++) {
            for (i = 0; i < my_size + 2; i++) {
                for (j = 0; j < WIDTH; j++) {
                    a[i][j] = b[i][j] = 0;
                    if (i >= 1 && i <= my_size)
                        a[i][j] = BigMatrix[(k - 1) * my_size + i - 1][j];
                }
            }

            MPI_Send(&a[0][0], (my_size + 2) * WIDTH, MPI_DOUBLE, k, 0,
                    MPI_COMM_WORLD);
        }

        for (i = 1; i < np_size; i++) {
            MPI_Recv(&counter[i], 1, MPI_INT, i, 0, MPI_COMM_WORLD, &status);
            MPI_Recv(&BigMatrix[(i - 1) * my_size][0], my_size * WIDTH,
                    MPI_DOUBLE, i, 0, MPI_COMM_WORLD, &status);
            result += counter[i];
        }

        cout << "\tResult :" << result << endl;

        for (i = 1; i < HEIGHT - 1; i++) {
            for (j = 1; j < WIDTH - 1; j++)
                cout << BigMatrix[i][j] << " ";
            cout << endl;
        }
    } else {
        MPI_Recv(&a[0][0], (my_size + 2) * WIDTH, MPI_DOUBLE, 0, 0,
                MPI_COMM_WORLD, &status);

        int left_id, right_id;

        left_id = (1 == my_id) ? MPI_PROC_NULL : my_id - 1;
        right_id = (np_size - 1 == my_id) ? MPI_PROC_NULL : my_id + 1;

        begin = (1 == my_id) ? 2 : 1;
        end = (np_size - 1 == my_id) ? my_size - 1 : my_size;

        while (1) {
            // 矩阵 a 用来接收数据
            MPI_Sendrecv(&a[my_size][0], WIDTH, MPI_DOUBLE, right_id, 0,
                    &a[0][0], WIDTH, MPI_DOUBLE, left_id, 0, MPI_COMM_WORLD,
                    &status);
            //cout<<"have in -sent recv one-"<<endl;
            MPI_Sendrecv(&a[1][0], WIDTH, MPI_DOUBLE, left_id, 0,
                    &a[my_size + 1][0], WIDTH, MPI_DOUBLE, right_id, 0,
                    MPI_COMM_WORLD, &status);
            //cout<<"have in -sent recv two-"<<endl;
            for (i = 0; i < my_size + 2; i++)
                for (j = 0; j < WIDTH; j++)
                    b[i][j] = a[i][j];

            // 计算，结果放入 b
            for (i = begin; i <= end; i++)
                for (j = 1; j < WIDTH - 1; j++)
                    b[i][j] = 0.25
                            * (a[i + 1][j] + a[i - 1][j] + a[i][j - 1]
                                    + a[i][j + 1]);

            bool flag = true;
            for (i = 1; i <= my_size; i++) {
                for (j = 1; j < WIDTH - 1; j++) {
                    if (fabs(a[i][j] - b[i][j]) > EPS) {
                        flag = false;
                        break;
                    }
                }
                if (!flag)
                    break;
            }
            //
            for (i = 0; i < my_size + 2; i++)
                for (j = 0; j < WIDTH; j++)
                    a[i][j] = b[i][j];

            if (flag)
                break;
        }

        int my_count = 0;
        for (i = begin; i <= end; i++)
            for (j = 1; j < WIDTH - 1; j++)
                if ((a[i][j] - 5.5) > EPS)
                    my_count++;

        //cout<<"myid "<<my_id<<" my_count "<<my_count<<endl;
        MPI_Send(&my_count, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
        MPI_Send(&a[1][0], my_size * WIDTH, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
    }

    MPI_Finalize();

    return 0;
}
