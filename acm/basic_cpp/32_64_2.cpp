/*
 * 32_64.cpp
 *
 *  Created on: 2018年4月9日
 *      Author: Lxx
 */

#include <cstdio>

void test(int array[], int size) {
    printf("The para size passed to test(): %d\n", size);
    printf("size of array[] in test(): %zu\n", sizeof(array));
    int num = sizeof(array) / sizeof(int);
    for (int i = 0; i < num && i < size; i++) {
        printf("%d ", array[i]);
    }
}

int main() {
    int array[] = {1,2,3,4};
    printf("size of int: %zu\n", sizeof(int));
    printf("size of array[] in main(): %zu\n", sizeof(array));
    test(array, sizeof(array)/sizeof(int));
    return 0;
}

