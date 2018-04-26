/*
 * 1.cpp
 *
 *  Created on: 2018年4月10日
 *      Author: Lxx
 */
#include <bits/stdc++.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <iostream>
//#include <algorithm>
using namespace std;

typedef long long ll;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void q_sort(int *array, int begin, int end) {
    int key = array[begin];
    int left = begin;
    int right = end;
    while (left < right) {
        while (array[left] <= key && left < right) {
            ++left;
        }
        while (array[right] >= key && left < right) {
            --right;
        }
        swap(array[left], array[right]);
//        printf("Swap index %d <==> %d\n", left, right);
    }
    swap(array[begin], array[left]);
    q_sort(array, begin, left - 1);
    q_sort(array, right + 1, end);
}

void quick_sort(int *array, int len) {
    q_sort(array, 0, len - 1);
}

int main() {
    int n;
    int array[] = {4, 5, 1, 9, 456, 23, 271};

    quick_sort(array, 7);

    for(int i = 0; i < 7; ++i) {
        printf("%d ", array[i]);
    }

    return 0;
}
