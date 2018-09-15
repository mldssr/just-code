/*
 * 1.cpp
 *
 *  Created on: 2018年4月10日
 *      Author: Lxx
 */
//#include <bits/stdc++.h>
//#include <stdio.h>
//#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    int nums[3];
    cin >> nums[0] >> nums[1] >> nums[2];
    sort(nums, nums + 3);
    int minus = nums[1] - nums [0];
    int ans = 0;
    if (minus % 2 == 0) {
        ans += minus / 2;
    } else {
        ans += (minus / 2 + 1);
        nums[2]++;
    }
    cout << ans + (nums[2] - nums[1]) << endl;

    return 0;
}
