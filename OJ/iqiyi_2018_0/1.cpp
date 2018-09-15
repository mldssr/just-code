/*
 * 1.cpp
 *
 *  Created on: 2018年4月10日
 *      Author: Lxx
 */
//#include <bits/stdc++.h>
#include <stdio.h>
//#include <stdlib.h>
#include <iostream>
//#include <algorithm>
using namespace std;

typedef long long ll;

int pai[2][13];

int cur = 0;

void fix(int left) {
    int pre = cur;
    cur = cur ^ 1;
    int index = 12;
    int left_index = left - 1;
    int right_index = 12;
    while (index >= 0) {
        if (left_index >= 0) {
            pai[cur][index] = pai[pre][left_index];
            --index;
            --left_index;
        }
        if (right_index >= left) {
            pai[cur][index] = pai[pre][right_index];
            --index;
            --right_index;
        }
    }
}

int main() {
    for (int i = 0; i < 13; ++i) {
        scanf("%d", &pai[0][i]);
    }
    int n;
    scanf("%d", &n);

    int left = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &left);
        fix(left);
    }

    for (int i = 0; i < 12; ++i) {
        printf("%d ", pai[cur][i]);
    }
    printf("%d", pai[cur][12]);

    return 0;
}

/*
1 2 3 4 5 6 7 8 9 10 11 12 13
2
6 1

 */
