/*
 *
 */

#include <cstdio>
#include <iostream>

using namespace std;

// 二分查找，返回下标
int binary_search(int* array, int length, int target) {
    int low = 0;
    int high = length - 1;
    int mid;

    if (array[low] > target || array[high] < target) {
        return -1;
    }

    while (low <= high) {
        mid = low + ((high - low) >> 1);  //防止溢出，移位也更高效
        printf("low mid high: %d %d %d\n", low, mid, high);
        if (array[mid] < target) {  // 不等的情况更多，放前面
            low = mid + 1;
        } else if (array[mid] > target) {
            high = mid - 1;
        } else {
            return mid;
        }
    }

    return -1;
}

int main() {
    int array[] = {0, 10, 20, 30, 40, 50, 60, 70};
    int index = binary_search(array, sizeof(array) / sizeof(int), -1);
    cout << "Find target at index " << index << endl;
    return 0;
}