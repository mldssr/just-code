/*
 * 构造与析构过程：
 * 对象的构造过程中，首先完成`父类`的构造函数，再完成`成员对象`的构造，最后调用`当前类`的构造函数
 */

#include <iostream>

using namespace std;



int main() {
    cout<<"=============="<<endl;
    Man man;
    cout<<"=============="<<endl;
    return 0;
}