

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
    try
    {
        d2 & der_2 = dynamic_cast<d2&>(der_1) ;
    }
    catch(exception & e)
    {
        cout<<e.what() ; 
    }
    return 0 ;
}
