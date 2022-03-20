#include<iostream>
using namespace std ;
int main()
{
    char c = 'd' ;
    int *p = static_cast<int *>(&c) ;
    *p = 10 ;
    cout<<c ;
    return 0 ;
}
