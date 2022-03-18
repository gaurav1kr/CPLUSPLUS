#include<iostream>
#include<vector>
using namespace std ;

struct A
{
    int *ptr ;
    A()
    {
        cout<<"default cons called" ;
        ptr = new int ;
    }
    A(const A & a1)
    {
        cout<<"copy cons called" ;
        this->ptr = new int ; 
    }
    ~A()
    {
        cout<<"Destructor called" ;
        delete ptr ;
    }
};

int main()
{
    vector<A> v1 ;
    v1.push_back(A()) ;
    return 0 ;
}
