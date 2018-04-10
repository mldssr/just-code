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
 * 质因数分解，C(n,m)=n!/(m!*(n-m)!)，
 * 设n!分解因式后，质因数p的次数为a；对应地m!分解后p的次数为b；(n-m)!分解后p的次数为c；则C(n,m)分解后，p的次数为a-b-c。
 * 计算出所有质因子的次数，它们的积即为答案，即C(n,m)=p1^(a1-b1-c1) * p2^(a2-b2-c2) * … * pk^(ak-bk-ck)。
 * n!分解后p的次数为：n/p + n/p^2 + … + n/p^k。
 * 算法的时间复杂度比前两种方案都低，基本上跟n以内的素数个数呈线性关系，
 * 而素数个数通常比n都小几个数量级，例如100万以内的素数不到8万个。
 * 用筛法生成素数的时间接近线性。该方案1秒钟能计算 1kw数量级的组合数。
 * 如果要计算更大，内存和时间消耗都比较大。
 *
 */

//用筛法生成素数
//const int MAXN = 1000000;
const int MAXN = 50;
bool arr[MAXN + 1] = { false };     // 值为 0 表示是素数
// 返回小于等于 MAXN 的所有素数
vector<int> produce_prim_number() {
    vector<int> prim;
    prim.push_back(2);
    int i, j;
    // 从 3 开始，检查所有奇数：若 i 为素数，则 i^2, i^2+i, i^2+2i, i^2+3i... 不是素数
    // 例如：MAXN 为 50，则：
    // 3 is prime, the following nums are not prime: 9 12 15 18 21 24 27 30 33 36 39 42 45 48
    // 5 is prime, the following nums are not prime: 25 30 35 40 45 50
    // 7 is prime, the following nums are not prime: 49
    for (i = 3; i * i <= MAXN; i += 2) {
        if (!arr[i]) {
            prim.push_back(i);      // Find a prime: i
            for (j = i * i; j <= MAXN; j += i) { // the following nums are not prime: j
                arr[j] = true;
            }
        }
    }
    // 至此，已完成所有奇数的标记工作
    // 下面将余下的素数取出
    while (i <= MAXN) {
        if (!arr[i]) {
            prim.push_back(i);
            printf("%d is prime.\n", i);
        }
        i += 2;
    }
    return prim;
}

// 计算n!中素因子p的指数
// n!分解后p的次数为：n/p + n/p^2 + … + n/p^k。
int Cal(int n, int p) {
    int ans = 0;
    long long rec = p;
    while (n >= rec) {
        ans += n / rec;
        rec *= p;
    }
    return ans;
}

//计算n的k次方对M取模，二分法
int Pow(long long n, int k, int M) {
    long long ans = 1;
    while (k) {
        if (k & 1) {
            ans = (ans * n) % M;
        }
        n = (n * n) % M;
        k >>= 1;
    }
    return ans;
}

// 计算 C(n,m) = n!/(m!*(n-m)!)
// C(n,m)=p1^(a1-b1-c1) * p2^(a2-b2-c2) * … * pk^(ak-bk-ck)
int comb3(int n, int m) {
    const int M = 10007;
    vector<int> prim = produce_prim_number();
    long long ans = 1;
    int exp;
    for (int i = 0; i < prim.size() && prim[i] <= n; ++i) {
        int primi = prim[i];
//        printf("Prime_%d: %d\n", i, primi);
        exp = Cal(n, primi) - Cal(m, primi) - Cal(n - m, primi);
        ans = (ans * Pow(primi, exp, M)) % M;
    }
    return ans;
}

int main(void) {
    int m, n;

    scanf("%d%d", &n, &m);
    printf("%d\n", comb3(n, m));

    return 0;
}
