#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;

    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    sort(arr, arr + n);

    int left = 1;
    int right = n - 2;
    int mn = arr[0];
    int mx = arr[n - 1];
    int ans = arr[n - 1] - arr[0];

    while (left < right) {
        ans += (mx - arr[left]) + (arr[right] - mn);
        mx = arr[right];
        mn = arr[left];
        ++left;
        --right;
    }
    if (left == right) {
        ans += max(mx - arr[left], arr[right] - mn);
    }

    printf("%d", ans);

    return 0;
}
