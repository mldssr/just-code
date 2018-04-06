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
 * 暴力求解，C(n,m)=n*(n-1)*...*(n-m+1)/m!
 * 这种方案的缺陷是，在计算过程中很快ans就溢出了，一般情况下，n不能超过12。
 * 补救办法之一是将先乘后除改为交叉地进行乘除，先除能整除的，但也只能满足n稍微增大的情况，n最多只能满足两位数。
 * 补救办法之二是换用高精度运算，这样结果不会有问题，只是需要实现大数相乘、相除和取模等运算，实现起来比较麻烦，时间复杂度为O(n)。
 */

int comb1(int n, int m) {
    const int M = 10007;
    int ans = 1;
    for (int i = n; i >= (n - m + 1); --i)
        ans *= i;
    while (m)
        ans /= m--;
    return ans % M;
}

int main(void) {
    int m, n;
    scanf("%d%d", &n, &m);
    printf("%d\n", comb1(n, m));

    return 0;
}
