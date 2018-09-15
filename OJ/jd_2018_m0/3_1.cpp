/*
 * 3_1.cpp
 *
 *  Created on: 2018年4月10日
 *      Author: Lxx
 */
// https://www.nowcoder.com/discuss/72826?type=0&order=0&pos=22&page=1

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// dp[i][j] 表示棋子某一步落到 (x, y) 的情况数
// 某一步的结果记录在了 dp[][][0] 中，则下一步记录在  dp[][][1] 中，再下一步又是 dp[][][0]
ll dp[10][10][3];
ll mod = 1e9 + 7;
int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };

int check(int x, int y) {
    if (x >= 0 && x <= 8 && y >= 0 && y <= 8)
        return true;
    return false;
}

// 计算新的一步后，棋子落到点 (x, y) 的情况数
void cal(int x, int y, int state) {
    dp[x][y][state] = 0;
    for (int i = 0; i < 8; i++) {
        // (tx, ty) 为上一步可能的位置，共8种
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (check(tx, ty)) {
            dp[x][y][state] = (dp[x][y][state] + dp[tx][ty][state ^ 1]) % mod;
        }
    }
}

int main() {
    int K;
    cin >> K;
    int state = 0, nowstate;
    dp[0][0][0] = 1;
    while (K--) {
        state = state ^ 1;          // state 的值 0/1 交错，用于区分这一步和上一步
        for (int i = 0; i <= 8; i++) {
            for (int j = 0; j <= 8; j++) {
                cal(i, j, state);
            }
        }
    }
    int x, y;
    cin >> x >> y;
    cout << dp[x][y][state] << endl;
    return 0;
}

