#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
    int cases;

    cin >> cases;
    for (int i = 0; i < cases; i++) {
        int len;
        cin >> len;
        char str[len + 1];
        scanf("%s", str);

        int index = 0;
        int count = 0;
        while (index < len) {
            if (str[index] == 'X') {
                ++index;
                continue;
            }
            ++count;
            index += 3;
        }
        printf("%d\n", count);
    }
    return 0;
}
