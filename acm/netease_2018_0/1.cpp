#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;

    cin >> str;
    int count = 0;
    for (int i = 0; i < 26; i++) {
        size_t index = str.find('A' + i);
        if (index != string::npos) count++;
    }
    int ans = 2;
    if (count > 2) {
        ans = 0;
    } else if (count == 1) {
        ans = 1;
    }
    cout << ans << endl;
    return 0;
}
