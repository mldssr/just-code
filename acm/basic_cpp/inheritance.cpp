#include <iostream>
using namespace std;

class A {
public:
    A() {
        cout << "A" << endl;
    }
    ~A() {
        cout << "~A" << endl;
    }
};

class B: public A {
public:
    B() {
        cout << "B with no para." << endl;
    }
    B(A &a) :
            _a(a) {
        cout << "B" << endl;
    }

    ~B() {
        cout << "~B" << endl;
    }

private:
    A _a;
};

int main(void) {
    A a;           // 很简单，定义a的时候调用了一次构造函数
    cout << "====================" << endl;
    B b(a);
    cout << "====================" << endl;
}
