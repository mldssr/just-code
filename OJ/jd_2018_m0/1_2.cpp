// https://www.nowcoder.com/discuss/72838

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

// 先打表出素数表，然后唯一分解定理求出所有素数的最大指数，然后快速幂

#define mod 987654321
#define maxn 100010

// 计算x的n次方对 mod 取模，二分法
ll Pow(int x, int n) {
    ll ans = 1;
    while (n) {
        if (n & 1)
            ans = ans * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return ans;
}

bool vis[maxn];     // 已被自动初始化为 0，值为 0 表示是质数
int prim[maxn];     // 素数表
int len = 0;        // 素数的个数

void init() {
    for (int i = 2; i < maxn; i++) {
        if (vis[i])
            continue;
        for (int j = 2 * i; j < maxn; j += i)
            vis[j] = true;
    }
    for (int i = 2; i < maxn; i++)
        if (!vis[i])
            prim[len++] = i;
}

int num[maxn];  // 存放最小公倍数的素数分解式，下标为素数，值为指数

// 将 n 的唯一分解，并合并到 num 中去
void merge(int n) {
    for (int j = 0; prim[j] * prim[j] <= n; j++) {  // 将 n 唯一分解
        int cnt = 0;    // prim[j] 的指数
        while (n % prim[j] == 0) {
            n /= prim[j];
            cnt++;
        }
        num[prim[j]] = max(num[prim[j]], cnt);
    }
    if (n > 1)  // 当 prim[j] * prim[j] > n 时，说明最多只剩下一个素数，若 n>1，则 n 为最后一个素数
        num[n] = max(num[n], 1);
}

int main() {
    init();
    int n, t;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        merge(i);
    }
    ll ans = 1;
    for (int i = 2; i < maxn; i++) {
        ans = ans * Pow(i, num[i]) % mod;
    }
    printf("%lld\n", ans);
    return 0;
}
