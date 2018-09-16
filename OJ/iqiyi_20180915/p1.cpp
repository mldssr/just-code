/*
幸运ID
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 131072KB；其他语言 655360KB
题目描述：
小C有一张票，这张票的ID是长度为6的字符串，每个字符都是数字，他想让这个ID变成他的辛运ID，所以他就开始更改ID，每一次操作，他可以选择任意一个数字并且替换它。

如果这个ID的前三位数字之和等于后三位数字之和，那么这个ID就是辛运的。你帮小C求一下，最少需要操作几次，能使ID变成辛运ID

输入
输入只有一行，是一个长度为6的字符串。

输出
输出这个最小操作次数


样例输入
000000
样例输出
0

Hint
输入样例2
000018

输出样例2
1

样例解释：将前三位任意一个改为9即可满足条件，操作数为1
 */

// 注：此代码过了91%
// #include <bits/stdc++.h>
// #include <algorithm>
#include <cstdio>
// #include <cstdlib>
// #include <cstring>
// #include <iostream>

// using namespace std;

// typedef long long ll;

// 返回第几个数最大，一样大返回前面的
int max_index(int a, int b, int c) {
    int index = 0;
    if (a < b) {
        a = b;
        ++index;
    }
    if (a < c) {
        ++index;
    }
    return index;
}

int main() {
    int num[6];
    char tmp;
    for (int i = 0; i < 6; ++i) {
        scanf("%c", &tmp);
        num[i] = tmp - '0';
    }

    int ops = 0;
    int sum0 = num[0] + num[1] + num[2];
    int sum1 = num[3] + num[4] + num[5];
    if (sum0 > sum1) {  // 使左边的和小
        for (int i = 0; i < 3; ++i) {
            int tmp = num[i];
            num[i] = num[i + 3];
            num[i + 3] = tmp;
        }
        sum0 = num[0] + num[1] + num[2];
        sum1 = num[3] + num[4] + num[5];
    }
    while (sum0 < sum1) {
        // for (int i = 0; i < 6; ++i) {
        //     printf("%d", num[i]);
        // }
        // printf("\n");
        int diff = sum1 - sum0;
        int l_index = max_index(9 - num[0], 9 - num[1], 9 - num[2]);  // 左边增大
        int r_index = max_index(num[3], num[4], num[5]) + 3;    // 右边减小
        int l_up = 9 - num[l_index];
        int r_down = num[r_index];
        if (l_up > r_down) {  // 左边增大
            num[l_index] += (l_up < diff ? l_up : diff);
        } else {  // 右边减小
            num[r_index] -= (r_down < diff ? r_down : diff);
        }
        sum0 = num[0] + num[1] + num[2];
        sum1 = num[3] + num[4] + num[5];
        ++ops;
    }

    printf("%d", ops);

    return 0;
}