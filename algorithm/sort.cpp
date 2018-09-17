/*
 * sort.cpp
 *
 *  Created on: Feb 27, 2018
 *      Author: lxx
 */

// From: http://blog.csdn.net/jnu_simba/article/details/9705111
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

void swap1(int *left, int *right) {
    int temp = *left;
    *left = *right;
    *right = temp;
}

void swap2(int &left, int &right) {
    int temp = left;
    left = right;
    right = temp;
}

void swap3(int &left, int &right) {
    if (&left != &right) {
        left ^= right;
        right ^= left;
        left ^= right;
    }
}

/*****************************************************************/
// 冒泡排序  稳定  时间复杂度最好的情况为O(n)，最坏的情况是O(n^2)
// 基本思想：两两比较相邻记录的关键字，如果反序则交换
void BubbleSort1(int arr[], int num) {
    int i, j;
    for (i = 0; i < num; i++) {
        for (j = 1; j < num - i; j++) {
            if (arr[j - 1] > arr[j]) swap1(&arr[j - 1], &arr[j]);
        }
    }
}

// 改进思路：设置标志位，明显如果有一趟没有发生交换（flag = false)，
// 说明排序已经完成。
void BubbleSort2(int arr[], int num) {
    int k = num;
    int j;
    bool flag = true;
    while (flag) {
        flag = false;
        for (j = 1; j < k; j++) {
            if (arr[j - 1] > arr[j]) {
                swap1(&arr[j - 1], &arr[j]);
                flag = true;
            }
        }
        k--;
    }
}

// 改进思路：记录一轮下来标记的最后位置，下次从头部遍历到这个位置就Ok
void BubbleSort3(int arr[], int num) {
    int k, j;
    int flag = num;
    while (flag > 0) {
        k = flag;
        flag = 0;
        for (j = 1; j < k; j++) {
            if (arr[j - 1] > arr[j]) {
                swap1(&arr[j - 1], &arr[j]);
                flag = j;
            }
        }
    }
}
/*************************************************************************/

/**************************************************************************/
// 插入排序  稳定  时间复杂度也为O(n^2)  比冒泡法和选择排序的性能要更好一些
// 将一个记录插入到已经排好序的有序表中，从而得到一个新的、记录数增1的有序表
// 即先排前两个，再排前三个。。。
void InsertionSort(int arr[], int num) {
    int temp;
    int i, j;
    for (i = 1; i < num; i++) {
        temp = arr[i];
        for (j = i; j > 0 && arr[j - 1] > temp; j--) {
            arr[j] = arr[j - 1];
        }
        arr[j] = temp;
    }
}

/****************************************************************************/

// 希尔排序  不稳定  时间复杂度为O(n^3/2),要好于直接插入排序的O(n^2)
// 先将整个待排元素序列分割成若干子序列（由相隔某个“增量”的元素组成的），
// 分别进行直接插入排序，然后依次缩减增量再进行排序，
// 待整个序列中的元素基本有序（增量足够小）时，再对全体元素进行一次直接插入排序（增量为1）
void ShellSort(int *arr, int N) {
    int i, j, increment;
    int tmp;
    for (increment = N / 2; increment > 0; increment /= 2) {
        for (i = increment; i < N; i++) {
            tmp = arr[i];
            for (j = i; j >= increment; j -= increment) {
                if (arr[j - increment] > tmp)
                    arr[j] = arr[j - increment];
                else
                    break;
            }
            arr[j] = tmp;
        }
    }
}

/**************************************************************************/
// 简单选择排序(simple selection sort)  稳定
// 尽管与冒泡排序同为O(n^2)，但简单选择排序的性能要略优于冒泡排序
// 就是通过n-i次关键字之间的比较，从n-i+1个记录中选择关键字最小的记录，
// 并和第i(1<=i<=n)个记录交换之
// 即：先把最小的归位，再把次小的归位。。。
void SelectSort(int arr[], int num) {
    int i, j, Mindex;
    for (i = 0; i < num; i++) {
        Mindex = i;
        for (j = i + 1; j < num; j++) {
            if (arr[j] < arr[Mindex]) Mindex = j;
        }
        swap1(&arr[i], &arr[Mindex]);
    }
}

/********************************************************************************/
// 归并排序  稳定
// 假设初始序列含有n个记录,则可以看成n个有序的子序列,每个子序列的长度为1,然后
// 两两归并,得到(不小于n/2的最小整数)个长度为2或1的有序子序列,再两两归并,...
// 如此重复,直至得到一个长度为n的有序序列为止,这种排序方法称为2路归并排序
// 时间复杂度为O(nlogn)，空间复杂度为O(n+logn)，
// 如果非递归实现归并,则避免了递归时深度为logn的栈空间，空间复杂度为O(n)

/*lpos is the start of left half, rpos is the start of right half*/
static void merge(int a[], int tmp_array[], int lpos, int rpos, int rightn) {
    int i, leftn, num_elements, tmpos;

    leftn = rpos - 1;
    tmpos = lpos;
    num_elements = rightn - lpos + 1;

    /*main loop*/
    while (lpos <= leftn && rpos <= rightn) {
        if (a[lpos] <= a[rpos])
            tmp_array[tmpos++] = a[lpos++];
        else
            tmp_array[tmpos++] = a[rpos++];
    }

    while (lpos <= leftn) /*copy rest of the first part*/
        tmp_array[tmpos++] = a[lpos++];
    while (rpos <= rightn) /*copy rest of the second part*/
        tmp_array[tmpos++] = a[rpos++];

    /*copy array back*/
    for (i = 0; i < num_elements; i++, rightn--) a[rightn] = tmp_array[rightn];
}

static void msort(int a[], int tmp_array[], int left, int right) {
    int center;

    if (left < right) {
        center = (right + left) / 2;
        msort(a, tmp_array, left, center);
        msort(a, tmp_array, center + 1, right);
        merge(a, tmp_array, left, center + 1, right);
    }
}

void merge_sort(int a[], int n) {
    int *tmp_array;
    tmp_array = (int *)malloc(n * sizeof(int));

    if (tmp_array != NULL) {
        msort(a, tmp_array, 0, n - 1);
        free(tmp_array);
    } else
        printf("No space for tmp array!\n");
}

/************************************************************************************/
// 堆排序  不稳定
// 堆是具有下列性质的完全二叉树：每个节点的值都大于或等于其左右孩子节点的值，称为大顶堆；
// 或者每个节点的值都小于或等于其左右孩子节点的值，称为小顶堆
// 堆排序就是利用堆进行排序的方法，
// 基本思想是：将待排序的序列构造成一个大顶堆。此时,整个序列的最大值就是堆顶的根结点。
// 将它移走(其实就是将其与堆数组的末尾元素交换，此时末尾元素就是最大值)，
// 然后将剩余的n-1个序列重新构造成一个堆,这样就会得到n个元素的次大值。
// 如此反复执行,便能得到一个有序序列了
// 时间复杂度为 O(nlogn)，好于冒泡、简单选择、直接插入的O(n^2)

// 构造大顶堆
#define leftChild(i) (2 * (i) + 1)

static void percDown(int *arr, int i, int N) {
    int tmp, child;
    for (tmp = arr[i]; leftChild(i) < N; i = child) {
        child = leftChild(i);
        // 左右子节点中选取较大的一个
        if (child != N - 1 && arr[child + 1] > arr[child]) {
            child++;
        }
        if (arr[child] > tmp)
            arr[i] = arr[child];
        else
            break;
    }
    arr[i] = tmp;
}

void HeapSort(int *arr, int N) {
    int i;
    // 构造大顶堆
    for (i = N / 2; i >= 0; i--) percDown(arr, i, N);
    // 将堆顶和堆底元素交换，之后将底部上升，最后重新调用 Max-Heapify 保持最大堆性质
    for (i = N - 1; i > 0; i--) {
        swap1(&arr[0], &arr[i]);
        percDown(arr, 0, i);
    }
}

/************************************************************************************/
// 快速排序  不稳定  时间复杂度为O(nlogn)
// 通过一趟排序将要排序的数据分割成独立的两部分，
// 其中一部分的所有数据都比另外一部分的所有数据都要小，
// 然后再按此方法对这两部分数据分别进行快速排序，
// 整个排序过程可以递归进行，以此达到整个数据变成有序序列。
// 快排函数，ary为待排序数组，left为待排序的左边界，right为右边界
static void q_sort(int arr[], int left, int right) {
    printf("===================== q_sort(): index %d --- %d\n", left, right);
    if (left >= right) return;
    int key = arr[left];  // 取最左边的为基准数
    int lp = left;        // 左指针
    int rp = right;       // 右指针
    while (lp < rp) {
        while (arr[rp] >= key && lp < rp) {
            --rp;
        }
        while (arr[lp] <= key && lp < rp) {
            ++lp;
        }
        swap1(&arr[lp], &arr[rp]);
        printf("Swap: %d <==> %d\n", lp, rp);
    }
    swap1(&arr[left], &arr[lp]);
    q_sort(arr, left, lp - 1);
    q_sort(arr, rp + 1, right);
}

void quick_sort(int arr[], int num) { q_sort(arr, 0, num - 1); }

/*****************计数排序*******************************/
// 计数排序(Counting sort)是一种稳定的排序算法。
// 计数排序使用一个额外的数组C，其中第i个元素是待排序数组A中值等于i的元素的个数。
// 然后根据数组C来将A中的元素排到正确的位置。
// 算法的步骤如下：
// 找出待排序的数组中最大和最小的元素
// 统计数组中每个值为i的元素出现的次数，存入数组C的第i项
// 对所有的计数累加（从C中的位置为1的元素开始，每一项和前一项相加）
// 反向填充目标数组：将每个元素i放在新数组的第C(i)项，每放一个元素就将C(i)减去1
void CountSort(int *arr, int num) {
    int mindata = arr[0];
    int maxdata = arr[0];
    for (int i = 1; i < num; i++) {
        if (arr[i] > maxdata) maxdata = arr[i];
        if (arr[i] < mindata) mindata = arr[i];
    }

    int size = maxdata - mindata + 1;
    //申请空间并初始化为0
    int *pCount = (int *)malloc(sizeof(int) * size);
    memset(pCount, 0, sizeof(int) * size);

    //记录排序计数，每出现一次在对应位置加1
    for (int i = 0; i < num; i++) ++pCount[arr[i] - mindata];

    //确定不比该位置大的数据个数
    for (int i = 1; i < size; i++)
        pCount[i] += pCount[i - 1];  //加上前一个的计数

    int *pSort = (int *)malloc(sizeof(int) * num);
    memset((char *)pSort, 0, sizeof(int) * num);

    //从末尾开始拷贝是为了重复数据首先出现的排在前面，即稳定排序
    for (int i = num - 1; i >= 0; i--) {
        //包含自己需要减1，重复数据循环回来也需要减1
        --pCount[arr[i] - mindata];
        pSort[pCount[arr[i] - mindata]] = arr[i];
    }
    //拷贝到原数组
    for (int i = 0; i < num; i++) arr[i] = pSort[i];

    free(pCount);
    free(pSort);
}

/*****************桶排序*****************************/
struct Node {
    int key_;
    struct Node *next_;
    Node(int key) {
        key_ = key;
        next_ = NULL;
    }
};

#define bucket_size 10  //与数组元素个数相等

void buck_sort(int arr[], int num) {
    Node *bucket_table[bucket_size];
    memset(bucket_table, 0, sizeof(bucket_table));

    //建立每一个头节点,头节点的key保存当前桶的数据量
    for (int i = 0; i < bucket_size; i++) bucket_table[i] = new Node(0);

    int maxValue = arr[0];
    for (int i = 1; i < num; i++) {
        if (arr[i] > maxValue) maxValue = arr[i];
    }

    for (int j = 0; j < num; j++) {
        Node *ptr = new Node(arr[j]);  //其余节点的key保存数据

        //映射函数计算桶号
        // index = (value * number_of_elements) / (maxvalue + 1)
        int index = (arr[j] * bucket_size) / (maxValue + 1);
        Node *head = bucket_table[index];
        //该桶还没有数据
        if (head->key_ == 0) {
            bucket_table[index]->next_ = ptr;
            (bucket_table[index]->key_)++;

        } else {
            //找到合适的位置插入
            while (head->next_ != NULL && head->next_->key_ <= ptr->key_)
                head = head->next_;
            ptr->next_ = head->next_;
            head->next_ = ptr;
            (bucket_table[index]->key_)++;
        }
    }

    //将桶中的数据拷贝回原数组
    int m, n;
    for (m = 0, n = 0; n < num && m < bucket_size; m++, n++) {
        Node *ptr = bucket_table[m]->next_;
        while (ptr != NULL) {
            arr[n] = ptr->key_;
            ptr = ptr->next_;
            n++;
        }
        n--;
    }

    //释放分配的动态空间
    for (m = 0; m < bucket_size; m++) {
        Node *ptr = bucket_table[m];
        Node *tmp = NULL;
        while (ptr != NULL) {
            tmp = ptr->next_;
            delete ptr;
            ptr = tmp;
        }
    }
}

/****************************************************/

/******************** 基数排序LSD*********************/

void base_sort_ISD(int *arr, int num) {
    Node *buck[10];  // 创建一个链表数组
    Node *tail[10];  //保存每条链表尾节点指针集合，
    //这样插入buck数组时就不用每次遍历到末尾
    int i, MaxValue, kth, high, low;
    Node *ptr;
    for (MaxValue = arr[0], i = 1; i < num; i++)
        MaxValue = max(MaxValue, arr[i]);

    memset(buck, 0, sizeof(buck));
    memset(tail, 0, sizeof(buck));

    for (low = 1; high = low * 10, low < MaxValue; low *= 10) {
        //只要没排好序就一直排序
        for (i = 0; i < num; i++) {
            //往桶里放
            kth = (arr[i] % high) / low;  //取出数据的某一位，作为桶的索引
            ptr = new Node(arr[i]);  //创建新节点

            //接到末尾
            if (buck[kth] != NULL) {
                tail[kth]->next_ = ptr;
                tail[kth] = ptr;
            } else {
                buck[kth] = ptr;
                tail[kth] = ptr;
            }
        }
        //把桶中的数据放回数组中（同条链表是从头到尾）
        for (kth = 0, i = 0; kth < num; i++) {
            while (buck[i] != NULL) {
                arr[kth++] = buck[i]->key_;
                ptr = buck[i];
                buck[i] = buck[i]->next_;
                delete ptr;
            }
        }

        memset(tail, 0, sizeof(buck));
    }
}

int main(void) {
    int arr[] = {9, 2, 5, 8, 3, 4, 7, 1, 6, 10};
    //    HeapSort(arr, 10);
    //    ShellSort(arr, 10);
    quick_sort(arr, 10);
    for (int i = 0; i < 10; i++) cout << arr[i] << ' ';
    cout << endl;

    return 0;
}
