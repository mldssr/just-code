/*
 * 构造与析构过程：
 * 对象的构造过程中，首先完成`父类`的构造函数，再完成`成员对象`的构造，最后调用`当前类`的构造函数
 */

#include <iostream>

using namespace std;

class Haha
{
  public:
    Haha()
    {
        cout << "Haha()" << endl;
    }
    ~Haha()
    {
        cout << "~Haha()" << endl;
    }
};

class Life
{
  public:
    Life()
    {
        cout << "Life()" << endl;
    }
    ~Life()
    {
        cout << "~Life()" << endl;
    }
};

class Person: public Life
{
  public:
    Person()
    {
        cout << "Person()" << endl;
    }
    ~Person()
    {
        cout << "~Person()" << endl;
    }
};

class Man : public Person
{
  public:
    Man()
    {
        cout << "Man()" << endl;
    }
    ~Man()
    {
        cout << "~Man()" << endl;
    }
    private:
    Haha haha;
};

int main() {
    cout<<"=============="<<endl;
    Man man;
    cout<<"=============="<<endl;
    return 0;
}