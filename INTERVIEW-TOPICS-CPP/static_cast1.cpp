#include<iostream>
using namespace std ;
class base
{
};
class derived : private base
{

};
int main()
{
    derived d1 ;
    base *p = static_cast<base *>(&d1) ; // It will give compile time error
//    base *p = (base *)(&d1) ; // No error at compile time but can lead to undefined error as derived had inherited base privately 
    return 0 ;
}
