#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>

// #include <queue>
// #include <map>
// #include <set>
// #include <stack>
// #include <algorithm>
// #include <iterator>
using namespace std;

int n, w;
void dfs(int depth, int cur, int& ans, int *v) {
    if (depth >= n) return;

    if (cur + v[depth] < w) {
        ans++;
        dfs(depth + 1, cur + v[depth], ans, v);
    }
    dfs(depth + 1, cur, ans, v);
}

int main() {
    scanf("%d%d", &n, &w);
    int v[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }
    int ans = 1;
    dfs(0, 0, ans, v);
    printf("%d\n", ans);
    return 0;
}
