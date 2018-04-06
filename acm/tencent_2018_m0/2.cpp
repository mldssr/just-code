//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

long long cc(int m, int k) { // C(m,k)
    double ret = 1.0;
    int tmp = m - k;
    k = (k <= tmp) ? k : tmp;
    for (int i = 1; i <= k; ++i) {
        ret = ret * (m + 1 - i) / i;
    }
    return (long long) (ret + 0.8);
}

int main() {
    int k;
    long long a, x, b, y;
    scanf("%d", &k);
    scanf("%lld %lld %lld %lld", &a, &x, &b, &y);

    long long ans = 0;
    long long ans1, ans2;

    for (int i = 0; i <= x; i++) {
        int left = k - i * a;
        if (left % b == 0 && left <= b * y) {
            ans1 = cc(x, i) % 1000000007;
            ans2 = cc(y, left / b) % 1000000007;
            ans = (ans + (ans1 * ans2) % 1000000007) % 1000000007;
        }
    }
    printf("%lld", ans % 1000000007);

    return 0;
}
