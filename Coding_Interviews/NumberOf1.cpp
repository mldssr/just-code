/*
 * 1.cpp
 *
 *  Created on: 2018年4月28日
 *      Author: Lxx
 */
#include <bits/stdc++.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <iostream>
//#include <algorithm>
using namespace std;

typedef long long ll;

class Solution {
public:
    int NumberOf1(int n) {
        int count = 0;
        while (n != 0) {
            ++count;
            n = n & (n - 1);
        }
        return count;
    }
};

int main() {
    Solution slt;

    int num = -1;
    printf("Number of 1 in %d: %d\n", num, slt.NumberOf1(num));

    return 0;
}
