/*
 * 设计一个只能创建一个唯一实例的类——单例模式
 * 参考自：https://blog.csdn.net/sunkun2013/article/details/12764101
 */

#include <iostream>
using namespace std;
class Singleton
{
  private:
    static Singleton *instance;
    Singleton() { cout << "Singleton()" << endl; }
  public:
    static Singleton *getInstance()
    {
        if (instance == NULL)
        {
            instance = new Singleton();
        }
        return instance;
    }
};

Singleton* Singleton::instance = NULL;

int main() {
    cout<<"=============="<<endl;
    Singleton *ins = Singleton::getInstance();
    return 0;
}