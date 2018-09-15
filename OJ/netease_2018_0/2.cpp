#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;

    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    sort(array, array + n);
    int delta = (n > 1) ? array[1] - array[0] : 0;
    bool ans = true;
    for (int i = 0; i < n; i++) {
        if (array[i] != array[0] + i * delta) {
            ans = false;
            break;
        }
    }
    if (ans)
        cout << "Possible" << endl;
    else
        cout << "Impossible" << endl;
    return 0;
}
