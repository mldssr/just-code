//#include <cstdio>
//#include <cstring>
//#include <iostream>
//#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define DIST(a, b, c, d) ((a<c?c-a:a-c)+(b<d?d-b:b-d))

// 找到某个格子出现 k 个棋子的最小步数
int min_move(int x[], int y[], int n, int k) {
    int ret = INT_MAX;
    // 尝试每一个可能的聚集坐标，共 n^2 种可能
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // 选择距离坐标最近的k个棋子
            int dist[n];
            for (int m = 0; m < n; ++m) {
                dist[m] = DIST(x[i], y[j], x[m], y[m]);
            }
            sort(dist, dist + n);
            int alter = 0;
            for (int m = 0; m < k; m++) {
                alter += dist[m];
            }
            if (alter < ret) {
                ret = alter;
            }
        }
    }
    return ret;
}

int main() {
    int n;
    scanf("%d", &n);
    int x[n];
    int y[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &y[i]);
    }
    int ans[n];
    ans[0]=0;
    for (int i = 2; i <= n; ++i) {
        ans[i-1] = min_move(x, y, n, i);
    }
    for (int i = 0; i < n - 1; ++i) {
        printf("%d ", ans[i]);
    }
    printf("%d", ans[n-1]);
    return 0;
}
