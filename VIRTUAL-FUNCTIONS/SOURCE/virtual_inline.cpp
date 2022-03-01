#include <iostream>
using namespace std;
class Base
{
public:
    virtual void who()
    {
        cout << "I am Base\n";
    }
};
class Derived: public Base
{
public:
    void who()
    { 
        cout << "I am Derived\n";
    }
};
  
int main()
{
    Base ptr ; 
    ptr.who();
  
    return 0;
}
