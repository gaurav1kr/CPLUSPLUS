#include<iostream>
using namespace std ;
template<typename T1 , typename T2>
auto add(T1 a , T2 b) -> decltype(a+b)
{
    return(a+b) ;
}

int main()
{
    float a = 2.8 ;
    int b = 2 ;
    cout<<add(a,b)<<"\n"<<add(b,a) ;
    return 0 ;
}
