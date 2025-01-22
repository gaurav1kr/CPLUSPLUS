//Below program will be compiled with C++17 only. Below are the steps for it's compilation :- 
//1. Get the boost path (It might be in /opt or /usr)
//2. Compile it with include path - g++ -std=c++17 -I/opt/homebrew/Cellar/boost/1.87.0/include boost1.cpp -o boost1 -g 

#include<boost/multiprecision/cpp_int.hpp>
using namespace std ;
using namespace boost::multiprecision ;

cpp_int fact(int n)
{
    cpp_int fact = 1 ;
    for(int i=n;i>=1;i--)
    {
        fact *= i ;
    }
    return fact ;
}

int main()
{
    int n = 30 ;
    cout<<fact(n) ;
    return 0 ;
}
