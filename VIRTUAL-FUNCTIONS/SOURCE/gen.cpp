#include<iostream>
  
using namespace std;
  
class Base {
public:      
  
    // non-virtual by default
    virtual void show() {  
         cout<<"Base::show() called";
    }
};
  
class Derived: public Base {
public:      
    void show() {
         cout<<"Derived::show() called";
    }      
};
  
int main()
{
  Derived d;
  Base &b = d;   
  b.show(); 
  getchar();
  return 0;
}
