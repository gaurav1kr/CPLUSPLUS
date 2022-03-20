#include<iostream>
using namespace std ;
class convcons
{
    int x ;
    public:
    convcons(int v):x(v)
    {
        cout<<"Conv constructor called\n" ;
    }
    operator string()
    {
        cout<<"Conversion operator called\n" ;
        return (to_string(this->x)) ;
    }
};

int main()
{
   convcons cov(10) ; 
   string str1 = static_cast<string>(cov) ;
   cov = static_cast<convcons>(30) ;
   return 0 ;
}
