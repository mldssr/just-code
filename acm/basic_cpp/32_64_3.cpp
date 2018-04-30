/*
 * 32_64_3.cpp
 *
 *  Created on: 2018年4月30日
 *      Author: Lxx
 */

#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "sizeof(char):" << sizeof(char) << endl;
    cout << "sizeof(short):" << sizeof(short) << endl;
    cout << "sizeof(int):" << sizeof(int) << endl;
    cout << "sizeof(long):" << sizeof(long) << endl;
    cout << "sizeof(long long):" << sizeof(long long) << endl;
    cout << "sizeof(unsigned int):" << sizeof(unsigned int) << endl;
    cout << "sizeof(float):" << sizeof(float) << endl;
    cout << "sizeof(double):" << sizeof(double) << endl;
    void* pointer;
    cout << "sizeof(pointer):" << sizeof(pointer) << endl;

    return 0;
}

