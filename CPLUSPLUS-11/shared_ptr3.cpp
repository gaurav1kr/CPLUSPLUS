#include<iostream>
#include<string>
#include<memory>
using namespace std ;
class student
{
public:
    student()
    {
        cout<<"constructor called" ; 
    }
    ~student()
    {
        cout<<"destructor called" ;
    }
};
int main()
{ 
    student *p = new student ;
    shared_ptr<student> q(p) ;

    if(q.get() == p)
    {
        cout<<"sharing worked well\n" ;
    }
    return 0 ;
}
