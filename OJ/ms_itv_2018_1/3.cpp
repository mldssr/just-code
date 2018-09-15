/*
 * 1.cpp
 *
 *  Created on: 2018年4月10日
 *      Author: Lxx
 */
#include <bits/stdc++.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <iostream>
//#include <algorithm>
using namespace std;

typedef long long ll;

void bianli(Node *root) {
    if (!root) {
        return;
    }
    printf("This is node: ", root->data);

    if (root->l_child == NULL && root->r_child == NULL) {
        return;
    }
    if (root->l_child) {
        bianli(root->l_child);
    }
    if (root->r_child) {
        bianli(root->r_child);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    return 0;
}
