/*
 * 1.cpp
 *
 *  Created on: 2018年4月29日
 *      Author: Lxx
 */
#include <bits/stdc++.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <iostream>
//#include <algorithm>
using namespace std;

typedef long long ll;
/*
 * 大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。n<=39
 * 1 1 2 3 5 8 13 21 34 55 89 144
 */
class Solution {
public:
    int Fibonacci(int n) {
        int num = 1, pre = 0;
        while (n--) {
            num += pre;
            pre = num - pre;
        }
        return pre;
    }
};

int main() {
    Solution slt;

    for (int i = 1; i <= 39; ++i) {
        printf("%d ", slt.Fibonacci(i));
    }

    return 0;
}
