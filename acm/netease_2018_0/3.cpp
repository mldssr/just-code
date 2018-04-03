#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    char data[55];

    scanf("%s", data);
    int len     = strlen(data);
    int max     = 1;
    int cur_max = 1;
    for (int i = 0; i < len - 1; i++) {
        if ((data[i] == data[i + 1])) {
            if (max < cur_max) {
                max = cur_max;
            }
            cur_max = 1;
        } else {
            cur_max++;
        }
    }
    if (max < cur_max) {
        max = cur_max;
    }
    printf("%d", max);
    return 0;
}
