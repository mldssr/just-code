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
#include <string>
#include <algorithm>
using namespace std;

#define ll long long

int main() {
    string str;
    cin>>str;

    int ans = 0;
    if (str.length() == 1) {
        ans = 1;
    }

    cout<<ans;
    return 0;
}
