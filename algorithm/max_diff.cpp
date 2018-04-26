/*
 * max_diff.cpp
 *
 *  Created on: 2018年4月21日
 *      Author: Lxx
 */

/*
 问题：
 一个整数数组a[n]，在a[n]中找两个数字，使得下标大的数字减去下表小的数字所得的差值最大，即：
 在a[n]中找a[i] 和 a[j] ，使得a[i] - a[j] 的值最大，并且 i > j。
 */

#include <vector>

using namespace std;

// 不断的更新最小数，并每次比较当前数与最小数的差值与最优解的关系。实现一次遍历，时间复杂度O(N)。
int MaxDiff(const vector<int>& a) {
    int iMinIndex = 0;  //当前最小数下标
    int iLowIndex = 0;  //当前最优解的小数的下标
    int iUpIndex = 0;   //当前最优解的大数的下标
    for (int i = 1; i < a.size(); i++) {
        if (a[i] < a[iMinIndex]) //不断更新最小的数
            iMinIndex = i;
        else {
            int iMaxDiffTemp = a[iUpIndex] - a[iLowIndex]; //当前最优解
            if ((a[i] - a[iMinIndex]) > iMaxDiffTemp) { //发现新的最优解
                iLowIndex = iMinIndex;
                iUpIndex = i;
            }
        }
    }
    return a[iUpIndex] - a[iLowIndex];
}

