/*
 hdu2051，http://acm.hdu.edu.cn/showproblem.php?pid=2051
 输入一个数输出它的二进制形式。可以用简单的%2运算来求，用bitset更简单。
 */
#include <iostream>
#include <bitset>
using namespace std;

int main() {
    int n;

    while (cin >> n) {
        bitset<15> ans(n);
        bool flag = false;

        for (int i = 14; i >= 0; --i) {
            if (ans[i])
                flag = true;
            if (flag)
                cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}
