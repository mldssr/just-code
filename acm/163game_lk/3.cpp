/*
 * 1.cpp
 *
 *  Created on: 2018年4月10日
 *      Author: Lxx
 */
//#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define MOD (1000000007)
typedef long long ll;

struct Task {
    int left;
    int p;
    int r;

    bool operator <(const Task &a) const {
        return left > a.left;
    }
};

bool comp(const Task &t1, const Task &t2) {
    if (t1.r != t2.r) {
        return t1.r < t2.r;
    }
    return t1.p < t2.p;
}

Task task[100003];

int main() {
    int n;
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &task[i].p, &task[i].r);
            task[i].left = task[i].p;
        }
        sort(task, task + n, comp);

        priority_queue<Task> que;
        ll timer = 0;
        ll ans = 0;
        int i = 0;
        Task tmp;
        while (i < n) {
            while (i < n && task[i].r <= timer) {
                que.push(task[i]);
                ++i;
            }
            while (!que.empty() && i < n && task[i].r > timer) {
                tmp = que.top();
                que.pop();
                if (tmp.left + timer > task[i].r) {
                    tmp.left -= (task[i].r - timer);
                    timer = task[i].r;
                    que.push(tmp);
                    break;
                } else {
                    timer += tmp.left;
                    ans = (ans + timer) % MOD;
                }
            }
            if (!que.empty() && i < n) {
                timer = task[i].r;
            }
        }

        while (!que.empty()) {
            tmp = que.top();
            que.pop();
            timer += tmp.left;
            ans = (ans + timer) % MOD;
        }
        printf("%d\n", ans);
    }

    return 0;
}

/*
 2
 1 0
 2 0
 3
 1 1
 1 0
 1 1
 */
