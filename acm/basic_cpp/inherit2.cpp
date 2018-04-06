#include <iostream>
using namespace std;

class BaseX {
public:
    virtual ~BaseX(){};
    virtual void FunctionX(){};
};

class ClassY: public BaseX {
public:
    virtual void FuctionY(){};
};

class FatherZ: public ClassY {
public:
};

int main() {
    FatherZ aObject;
    BaseX *ptrX = &aObject;
    ClassY *ptrY = &aObject;
    FatherZ *ptrZ = &aObject;

    cout<<ptrX<<endl;
    cout<<ptrY<<endl;
    cout<<ptrZ<<endl;

    return 0;
}
