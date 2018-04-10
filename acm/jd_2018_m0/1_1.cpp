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
#include <algorithm>
using namespace std;

// 只过了 50%

typedef long long ll;

long gcd(long x, long y) {
    long r;
    do {
        r = x % y;
        x = y;
        y = r;
    } while (r);
    return x;
}

int main() {
    int n;
    scanf("%d", &n);
    ll i, y = 1;
    for (i = 2; i <= n; i++) {
        y = (y / gcd(i, y) * i ) % 987654321;
    }

    printf("%lld", y);
    return 0;
}
