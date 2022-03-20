
#include<iostream>
using namespace std ;
class base
{
    public:
        virtual void show()
        {
            cout<<"show from base" ;
        }
};

class d1 : public base
{
    public:
        void show()
        {
            cout<<"show from d1" ;
        }
};

class d2 : public base
{
    public:
        void show()
        {
            cout<<"show from d2" ;
        }
};

int main()
{
    d1 der_1 ;
    base *b = &der_1 ;
    d1 *der_2 = dynamic_cast<d1 *>(b) ; // success
    d2 *der_3 =  dynamic_cast<d2 *>(b) ; // will return NULL as it is invalid casting 
    if(der_2)
    {
        cout<<"typecasting successful" ;
    }
    else
    {
        cout<<"typecasting failed as returned NULL" ;
    }
    return 0 ;
}
