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
    int FirstNotRepeatingChar(string str) {
        // 0~9999: 1 time
        // -1: not known;
        // -2: more than once
        int pos[128];
        for (int i = 0; i < 128; ++i) {
            pos[i] = -1;
        }

        for (int i = 0; i < str.length(); ++i) {
            char tmp = str[i];
            if (pos[tmp] == -2) {   // Occur more than 1 time
                continue;
            } else if (pos[tmp] >= 0) {  // Occur 1 time already
                pos[tmp] = -2;
            } else {    // First occur
                pos[tmp] = i;
            }
        }

        int index = 0;
        int min_pos = 10000;
        for (int i = 0; i < 128; ++i) {
//        if(pos[i] != -1) {
//            printf("%c occurs first at pos %d.\n", i, pos[i]);
//        }
            if (pos[i] >= 0 && pos[i] < min_pos) {
                index = i;
                min_pos = pos[i];
            }
        }
        if (min_pos == 10000) {
            min_pos = -1;
        }
        return min_pos;
    }
};

int main() {
    Solution slt;
    string str = "zuDClOWjkPNhb";
    int min_pos = slt.FirstNotRepeatingChar(str);
    printf("%d\n", min_pos);

    return 0;
}
