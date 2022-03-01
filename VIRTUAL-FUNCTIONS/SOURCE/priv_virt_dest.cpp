#include<iostream>
using namespace std ;
class base
{
public:
     
    base() { std::cout << "base class constructor\n"; }
   
    virtual ~base()
    {
        std::cout << "base class destructor\n";
    }
    void show()
    {
        std::cout << "show() called on base class\n";
    }

    protected:    
    virtual void print()
    {
        std::cout << "print() called on base class\n";
    }
};
 
class derived : public base 
{
public:
    derived() : base()
    {
        std::cout << "derived class constructor\n";
    }
    virtual ~derived()
    {
        std::cout << "derived class destructor\n";
    }
 
private:
    virtual void print()
    {
        std::cout << "print() called on derived class\n";
    }
};
 
int main()
{
    std::cout << "printing with base class pointer\n";
    base* b_ptr = new derived();
     
    b_ptr->show();
     
    b_ptr->print();
 
    delete b_ptr;
}
