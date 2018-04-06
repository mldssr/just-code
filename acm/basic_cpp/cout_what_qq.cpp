//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getResult(vector<int> nums) {
    if (nums.size() == 0) {
        return 0;
    }

    int result = nums[0];
    int current = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        current = max(nums[i] + current, nums[i]);
        result = max(current, result);
    }
    return result;
}

int main() {
    int aa[] = { 1, 2, -1, 3, 4, 5, -10 };
    int bb[] = { -2, -3, -1, -5 };
    int cc[] = { -1, -2, 0, -3, -5 };

    vector<int> aaa(aa, aa + 7);
    vector<int> bbb(bb, bb + 4);
    vector<int> ccc(cc, cc + 5);

    printf("%d %d %d", getResult(aaa), getResult(bbb), getResult(ccc));

    return 0;
}
