#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>

// #include <queue>
// #include <map>
// #include <set>
// #include <stack>
// #include <algorithm>
// #include <iterator>
using namespace std;


int main() {
    int start, end;

    cin >> start >> end;

    char num[1000];
    int sum = 0;
    int count = 0;
    for (int i = 1; i <= end; i++) {
        sprintf(num, "%d", i);
        int len = strlen(num);
        for (int j = 0; j < len; j++) {
            sum += (num[j] - '0');
        }
        if (i >= start) {
            if (sum % 3 == 0) {
                ++count;
                sum = 0;
            }
        }
    }
    printf("%d", count);

    return 0;
}
