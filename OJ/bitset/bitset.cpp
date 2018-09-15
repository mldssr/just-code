#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <utility>
#include <algorithm>
#include <iterator>
#include <bitset>
using namespace std;

const int MAX_N = 30000 + 5;
bitset<MAX_N> ls[5][MAX_N]; // ls[j][i]表示第j个科目排名为1到i的是哪些人
bitset<MAX_N> ans;
int arr[5][MAX_N];          // arr[j][i]表示第j个科目排名为i的是谁
int _rank[5][MAX_N];        // _rank[j][i]表示第j个科目第i位同学的排名

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 5; ++j) {
            int val;
            scanf("%d", &val);
            arr[j][val] = i;
            _rank[j][i] = val;
        }
    }
    for (int j = 0; j < 5; ++j) {
        for (int i = 1; i <= n; ++i) {
            if (i == 1) {
                ls[j][i] = 0;
            } else {
                ls[j][i] = ls[j][i - 1];
                ls[j][i].set(arr[j][i - 1]); //名次从前往后走，依次将上一个人设为1
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        ans = ls[0][_rank[0][i]];
        for (int j = 1; j < 5; ++j) {
            ans &= ls[j][_rank[j][i]];
        }
        cout << ans.count() << endl;
    }
    return 0;
}
