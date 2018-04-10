/*
 * basic1.cpp
 *
 *  Created on: 2018年4月9日
 *      Author: Lxx
 */

#include <cstdio>
#include <cstdlib>

class Foo {
public:
    virtual void func1() {
        printf("This is Foo's virtual func1()\n");
    }
    void func2() {
        printf("This is func2()\n");
    }
    int data1;
    static int data2;
};

int Foo::data2 = 1;

int main() {
    // NOTE: the difference between malloc and new
    Foo *p_foo = (Foo *) malloc(sizeof(Foo));
//    Foo *p_foo = new Foo;
    printf("sizeof Foo: %d\n", sizeof(Foo));
    printf("sizeof a pointer: %d\n", sizeof(p_foo));

    p_foo->func1();         // malloc: OK, new: NO
    p_foo->func2();         // OK
    p_foo->data1 = 1;       // OK
    p_foo->data2 = 1;       // OK

    return 0;
}
