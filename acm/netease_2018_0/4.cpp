#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;

    cin >> n;
    int arr[n];
    int first = n / 2;
    int left  = first - 1;
    int right = first;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            cin >> arr[right];
            right++;
        } else {
            cin >> arr[left];
            left--;
        }
    }
    if (n % 2 == 0) {
        for (int i = 0; i < n - 1; i++) cout << arr[i] << " ";
        cout << arr[n - 1] << endl;
    } else {
        for (int i = n - 1; i > 0; i--) cout << arr[i] << " ";
        cout << arr[0] << endl;
    }
    return 0;
}
