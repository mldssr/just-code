/*
 * comb.cpp
 * 计算组合数 Combination: C(n,m), n >= m
 *  Created on: 2018年4月6日
 *      Author: Lxx
 */
// From: https://my.oschina.net/baoer1024/blog/62826

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

// 求解组合数C(n,m)，即从n个相同物品中取出m个的方案数，由于结果可能非常大，对结果模10007即可。

/*
 * 打表，C(n,m)=C(n-1,m-1)+C(n-1,m)
 * 由于组合数满足以上性质，可以预先生成所有用到的组合数，使用时，直接查找即可。
 * 生成的复杂度为O(n^2)，查询复杂度为O(1)。
 * 较方案一而言，支持的数量级大有提升，在1秒内，基本能处理10000以内的组合数。
 * 算法的预处理时间较长，另外空间花费较大，都是平方级的，优点是实现简单，查询时间快。
 */

const int M = 10007;
const int MAXN = 1000;
int C[MAXN + 1][MAXN + 1];
void initial() {
    int i, j;
    for (i = 0; i <= MAXN; ++i) {
        C[0][i] = 0;
        C[i][0] = 1;
    }
    for (i = 1; i <= MAXN; ++i) {
        for (j = 1; j <= MAXN; ++j)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % M;
    }
}

int comb2(int n, int m) {
    return C[n][m];
}


int main(void) {
    int m, n;
    initial();
    scanf("%d%d", &n, &m);
    printf("%d\n", comb2(n, m));

    return 0;
}
