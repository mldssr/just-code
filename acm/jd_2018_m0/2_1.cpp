/*
 * 2_1.cpp
 *
 *  Created on: 2018年4月10日
 *      Author: Lxx
 */
// https://www.nowcoder.com/discuss/72826?type=0&order=0&pos=22&page=1
/*
 * 第二题：去掉字符串构成回文。其实是经典的求回文子序列个数。
 * 但是我觉得题意是有坑的，题意描述的感觉不是这个意思。
 * 记忆化搜索dp。也可以直接dp。
 * 方程：
 * f[i][j] = dfs(i, j - 1) + dfs(i + 1, j) - dfs(i + 1, j - 1);
 * if(str[i] == str[j])
 * f[i][j] += dfs(i + 1, j - 1) + 1;
 */

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f[59][59];
string str;

ll dfs(int i, int j) {
    if (i > j) {
        return 0;
    }
    if (i == j) {
        f[i][j] = 1;
        return f[i][j];
    }
    if (f[i][j] != 0) {
        return f[i][j];
    }
    f[i][j] = dfs(i, j - 1) + dfs(i + 1, j) - dfs(i + 1, j - 1);
    if (str[i] == str[j])
        f[i][j] += dfs(i + 1, j - 1) + 1;
    return f[i][j];
}
int main() {
    cin >> str;
    int len = str.length();
    cout << dfs(0, len - 1) << endl;
    return 0;
}
