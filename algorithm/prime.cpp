/*
 * prime.cpp
 *
 *  Created on: 2018年4月9日
 *      Author: Lxx
 */

// https://blog.csdn.net/zw1996/article/details/50966032
// 唯一分解定理

//#include <bits/stdc++.h>
#include <cstdio>

#define MAXN 100

bool vis[MAXN + 1] = { 0 };
int prime[MAXN + 1] = { 0 };
int primes = 0;

void get_primes() {
    for (int i = 2; i <= MAXN; i++) {
        if (vis[i] == 0) {      // Find a prime: i
            prime[primes] = i;
            primes++;
            for (int j = i * i; j <= MAXN; j += i) {
                vis[j] = 1;
            }
        }
    }
}

/*
 * 计算幂次方，将 nn 的唯一分解结果的指数提出来，放入到 factor 中，且只存放非0的指数
 * 例如：50 = 2^1 * 5^2, 将 1, 2 放入到 factor 中，而不是 1, 0, 2
 * 前提：以将素数表生成到 prime[] 中
 */
int factor[MAXN + 1] = { 0 };
void getprimefactor(long long num) {
    int cas = 0;
    for (int i = 0; i < primes && prime[i] * prime[i] <= num; i++) {
        while (num % prime[i] == 0) { //可以整除
            factor[cas]++;
            num /= prime[i];
        }
        if (factor[cas] != 0) { //就是进入了while里面的
            cas++;
        }
    }
    if (num > 1) {
        factor[cas] = 1; //就是因为上面for条件的原因；prime[i]*prime[i]<=num当不满足这个条件的时候就应该还有一个素数的一次方
    }
}

/*
 * 计算幂次方，将 nn 的唯一分解结果的指数提出来，放入到 factor 中，也会记录为0的指数，和素数表对应
 * 例如：50 = 2^1 * 5^2, 将 1, 0, 2 放入到 factor 中，而不是 1, 2
 * 前提：以将素数表生成到 prime[] 中
 */
int exp[MAXN + 1] = { 0 };
void get_prime_exp(long long num) {
    for (int i = 0; i < primes && prime[i] <= num; i++) {
        while (num % prime[i] == 0) { //可以整除
            exp[i]++;
            num /= prime[i];
        }
    }
}

int main() {
    get_primes();
    get_prime_exp(23);
    for (int i = 0; i < 10; ++i) {
        printf("%d %d\n", prime[i], exp[i]);
    }
    return 0;
}
