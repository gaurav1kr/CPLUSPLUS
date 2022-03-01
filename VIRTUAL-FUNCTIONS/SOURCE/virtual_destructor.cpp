#include<iostream>
using namespace std ;
class base
{
    public:
        base()
        {
            cout<<"Base class constructor called\n";
        }
        virtual void print()
        {
            cout<<"In base" ;
        }
        virtual ~base()
        {
            cout<<"Base class destructor called\n" ;
        }
};

class derived : public base
{
    public:
        derived()
        {
            cout<<"Derivd class constructor called\n" ;
        }
        void print()
        {
            cout<<"In derived" ;
        }
        ~derived()
        {
            cout<<"Derived class destructor called\n" ;
        }
};

int main()
{
    derived *d1 = new derived;
    base *b1 = d1 ; 
    delete b1 ;
    return 0 ;
}
