#include<iostream>
using namespace std ;

class ops
{
    public:
        int num ;
        ops(int i):num(i){}
        ops * operator ->()
        {
            return this ;
        }
};
int main()
{
    ops obj1(15) ;   
    cout<<obj1->num ;
    return 0 ;
}
