/*

 */

// #include <bits/stdc++.h>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

// typedef long long ll;

class D {
   public:
    void printA() { cout << "printA" << endl; }
    void printB() {
        cout << "printB" << endl;
        cout << aa << endl;
    }
    virtual void printC() { cout << "printC" << endl; }

   private:
    int aa;
};

int main() {
    D *d = NULL;
    d->printA();    // OK
    d->printB();    // Crash!
    d->printC();    // Crash!
    return 0;
}