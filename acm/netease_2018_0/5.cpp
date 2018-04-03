#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int rent, fruits, money, price;

    cin >> rent >> fruits >> money >> price;
    int days = 0;
    if (money / rent < fruits) {
        days = money / rent;
    } else {
        days = (money - fruits * rent) / (price + rent) + fruits;
    }

    // while (money > 0) {
    //     money -= rent;
    //     if (fruits > 0) {
    //         --fruits;
    //     } else {
    //         money -= price;
    //     }
    //     if (money >= 0) {
    //         ++days;
    //     }
    // }
    cout << days;

    return 0;
}
