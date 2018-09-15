#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;
int N[100007][4];
struct ss {
    int l, r;
};
bool cmp(const ss &a, const ss &b) {
    return a.l < b.l;
}
struct ss M[100007];
int main() {
    //int M[100][2],N[100][4];
    int s, t;
    while (cin >> s) {
        //cin>>s;
        for (int i = 0; i < s; i++) {
            cin >> M[i].l >> M[i].r;
        }
        sort(M, M + s, cmp);
        cin >> t;
        for (int i = 0; i < t; i++) {
            cin >> N[i][0] >> N[i][1] >> N[i][2] >> N[i][3];
            int res = 0;
            for (int j = 0; j < s; j++) {
                if (M[j].l > N[i][1])
                    break;
                if (M[j].l >= N[i][0] && M[j].l <= N[i][1] && M[j].r >= N[i][2]
                        && M[j].r <= N[i][3]) {
                    res++;
                }
            }
            cout << res << endl;
        }
    }
    return 0;
}
