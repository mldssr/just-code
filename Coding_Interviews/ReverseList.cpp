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

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode *pre_node = NULL;
        ListNode *this_node = pHead;
        ListNode *tmp = NULL;

        while (this_node) {
            tmp = this_node->next;
            this_node->next = pre_node;
            pre_node = this_node;
            this_node = tmp;
        }
        return pre_node;
    }
};

int main() {
    Solution slt;

    ListNode *pHead = new ListNode(0);
    ListNode *cur = pHead;
    for (int i = 1; i < 5; ++i) {
        cur->next = new ListNode(i);
        cur = cur->next;
    }
    cur = pHead;
    for (int i = 0; i < 4; ++i) {
        printf("%d -> ", cur->val);
        cur = cur->next;
    }
    printf("%d\n", cur->val);

    pHead = slt.ReverseList(pHead);
    cur = pHead;
    for (int i = 0; i < 4; ++i) {
        printf("%d -> ", cur->val);
        cur = cur->next;
    }
    printf("%d\n", cur->val);

    return 0;
}
