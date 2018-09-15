/*
 * 1.cpp
 *
 *  Created on: 2018年4月10日
 *      Author: Lxx
 */
//#include <bits/stdc++.h>
#include <stdio.h>
//#include <stdlib.h>
//#include <iostream>
//#include <algorithm>
//using namespace std;

typedef long long ll;

const int MAXN = 501;
int C[MAXN + 1][MAXN + 1];
void initial() {
    int i, j;
    for (i = 0; i <= MAXN; ++i) {
        C[0][i] = 0;
        C[i][0] = 1;
    }
    for (i = 1; i <= MAXN; ++i) {
        for (j = 1; j <= MAXN; ++j)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]);
    }
}

int comb(int n, int m) {
    if (n < m)
        return 0;
    return C[n][m];
}

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
//    printf("M: %d\n", M);

    int num_t = 0, num_k = 0, num_s = 0;

    char tmp;
    for (int i = 0; i < N; ++i) {
        getchar();
        scanf("%c", &tmp);
//        printf("IN: %c\n", tmp);
        if (tmp == 'T') {
            ++num_t;
        } else if (tmp == 'K') {
            ++num_k;
        } else {
            ++num_s;
        }
    }

    int tmp1, tmp2;
    for (int i = 0; i < M; ++i) {
        scanf("%d %d", &tmp1, &tmp2);
//        printf("%d %d", tmp1, tmp2);
    }

    ll ans = comb(num_t, 3) + comb(num_t, 2) * num_k + comb(num_t, 2) * num_s
            + num_t * num_s * num_k - M * num_t;

    printf("%lld", ans);

    return 0;
}
