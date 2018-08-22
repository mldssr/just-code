#include <iostream>
#include <string>
using namespace std;

class Person
{
  public:
    Person()
    {
        cout << "Person()" << endl;
    }
    Person(const Person &p)
    {
        cout << "Copy Constructor" << endl;
    }

    Person &operator=(const Person &p)
    {
        cout << "Assign" << endl;
        return *this;
    }

  private:
    int age;
    string name;
};

void f(Person p)
{
    return;
}

Person f1()
{
    cout << "Begin f1()" << endl;
    Person p;
    cout << "End fi()" << endl;
    return p;
}

int main()
{
    Person p;
    cout << "=========================================" << endl;
    Person p1 = p; // 1
    cout << "=========================================" << endl;
    Person p2;
    cout << "=========================================" << endl;
    p2 = p; // 2
    cout << "=========================================" << endl;
    f(p2); // 3
    cout << "=========================================" << endl;

    p2 = f1(); // 4
    cout << "=========================================" << endl;

    Person p3 = f1(); // 5
    cout << "=========================================" << endl;

    // getchar();
    return 0;
}