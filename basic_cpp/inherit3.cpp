#include <iostream>
using namespace std;

class A {
    char a[2];
public:
    virtual void aa(){};
};

class B: public virtual A {
    char b[2];
    char a[2];
public:
    virtual void bb(){};
    virtual void aa(){};
};

class C: public virtual B {
    char a[2];
    char b[2];
    char c[2];
public:
    virtual void cc(){};
    virtual void aa(){};
    virtual void bb(){};
};

int main() {
    cout<<sizeof(A)<<" "<<sizeof(B)<<" "<<sizeof(C)<<endl;  // 8 16 28
    return 0;
}
