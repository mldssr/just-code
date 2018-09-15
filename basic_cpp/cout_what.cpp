/*
 * cout_what.cpp
 *
 *  Created on: 2018年4月4日
 *      Author: Lxx
 */
#include <cstdio>
#include <iostream>
//#include <bits/stdc++.h>
using namespace std;

/***************************************************************************/
void test() {
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
    int *p = arr;
    *(p++) += 89;
    printf("%d %d\n", *p, *(++p)); // 3 3
}

/***************************************************************************/
class base1 {
private:
    int a, b;
//    int b, a;
public:
    base1(int i) :
            b(i + 1), a(b) {
        printf("Constructor with para: a = %d, b = %d\n", a, b);    // 0 12
    }
    base1() :
            b(1), a(b) {
        printf("Constructor without para: a = %d, b = %d\n", a, b); // 0 1
    }
    int get_a() {
        return a;
    }
    int get_b() {
        return b;
    }
};
void test1() {
    base1 obj1(11);
    cout << obj1.get_a() << " " << obj1.get_b() << endl;
    base1 obj2;
    cout << obj2.get_a() << " " << obj2.get_b() << endl;
}

/***************************************************************************/

int main() {
    test1();
    return 0;
}

