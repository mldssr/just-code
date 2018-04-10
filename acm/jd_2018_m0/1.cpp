/*
 * 1.cpp
 *
 *  Created on: 2018年4月9日
 *      Author: Lxx
 */
//#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
int n;
//const int MAXN = 100000;
//bool arr[MAXN + 1] = { false };
vector<int> produce_prim_number(bool arr[]) {
    vector<int> prim;
    prim.push_back(2);
    int i, j;
    for (i = 3; i * i <= n; i += 2) {
        if (!arr[i]) {
            prim.push_back(i);
            for (j = i * i; j <= n; j += i)
                arr[j] = true;
        }
    }
    while (i <= n) {
        if (!arr[i])
            prim.push_back(i);
        i += 2;
    }
    return prim;
}
int main() {
    scanf("%d", &n);
    bool arr[100001] = { false };

    vector<int> vv = produce_prim_number(arr);
    ll ans = 1;
    vector<int>::iterator it = vv.begin();
    while (it != vv.end()) {
        ans = (ans * (*it)) % 987654321;
        ++it;
    }

    printf("%lld", ans);
    return 0;
}
