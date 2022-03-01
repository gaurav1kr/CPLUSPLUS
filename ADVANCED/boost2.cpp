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
