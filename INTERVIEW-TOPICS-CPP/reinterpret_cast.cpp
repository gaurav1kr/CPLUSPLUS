#include<iostream>
using namespace std ;
class student
{
    public:
    void studInfo()
    {
        cout<<"studinfo found" ;
    }
};

class employee
{
    public:
    void empInfo()
    {
        cout<<"empInfo found" ;
    }
};
int main()
{
    student *stud = new student ;
    employee *emp = reinterpret_cast<employee *>(stud) ;
    emp->empInfo() ;
    return 0 ;
}
