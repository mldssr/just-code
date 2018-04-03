#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int nn, mm, kk;

    scanf("%d%d%d", &nn, &mm, &kk);
    int ans = 0;

    int min_side = (kk - 1 < nn - kk) ? kk - 1 : nn - kk;
    int max_side = nn - 1 - min_side;

    int next_layer = 1;
    while (mm > 0 && ans < min_side) {
        mm -= next_layer;
        ++ans;
        next_layer += 2;
    }
    while (mm > 0 && ans < max_side) {
        mm -= next_layer;
        ++ans;
        next_layer += 1;
    }

    if ((mm > 0) && (nn != 0)) {
        ans += mm / nn;
    }

    if (kk == 0) {
        ans = 0;
    }

    if (kk == 1) {
        ans = mm;
    }
    printf("%d", ans);
    return 0;
}
