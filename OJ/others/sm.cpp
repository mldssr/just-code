#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int t = 10000;
    int y[20007];

    memset(y, 0x3f, sizeof(y));
    y[1] = 0;
    y[2] = 1;
    for (int i = 2; i <= t; i++) {
        y[i * 2] = min(y[i * 2], y[i] + 1);
        if (i % 2 == 0)
            for (int j = i + i / 2; j <= t; j += i / 2)
                y[j] = min(y[j], y[i] + (j - i) * 2 / i);
    }

    for (int i = 1; i <= 10; i++)
        cout << i << " " << y[i] << endl;

    int n;
    while (cin >> n)
        cout << y[n] << endl;
    return 0;
}
