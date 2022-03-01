#include<iostream>
using namespace std;
 
class Base
{
public:
    virtual ~Base() = 0 ; 
};

Base::~Base()
{
    cout<<"In base class destructor\n" ;
}

class Derived: public Base
{
public:
    ~Derived()
    {
        cout<<"Derived class destructor called\n" ;
    }
};
 
int main(void)
{
    Base *p = new Derived ;
    delete p ;
    return 0 ;
}
