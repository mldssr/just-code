#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, k;

    // 1 ≤ n ≤ 10, 1 ≤ k ≤ 10^5
    scanf("%d %d", &n, &k);

    int **state = new int *[n + 1];
    for (int i = 0; i < n + 1; i++) {
        state[i] = new int[k + 1]();
    }
    state[0][1] = 1;
//    state[0][1] = 1;

    int mod = 1000000007;

    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= k; j++) {
            sum = (sum + state[i - 1][j]) % mod;
        }
        for (int j = 1; j <= k; j++) {
            int invalid = 0;
            int p = 2;
            while (p * j <= k) {
                invalid = (invalid + state[i - 1][p * j]) % mod;
                p++;
            }
            state[i][j] = (sum - invalid + mod) % mod;
        }
    }

    int sum = 0;
    for (int i = 1; i <= k; i++) {
        sum = (sum + state[n][i]) % mod;
    }
    printf("%d", sum);

    return 0;
}
