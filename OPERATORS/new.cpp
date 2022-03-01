#include<iostream>
using namespace std ;
int main()
{
    int *p = new(nothrow) int ;
    if(!p)
    {
       cout<<"mem dealloc fail" ;
    }
    else
    {
       cout<<"work fine" ;
    }
    return 0 ;
}
