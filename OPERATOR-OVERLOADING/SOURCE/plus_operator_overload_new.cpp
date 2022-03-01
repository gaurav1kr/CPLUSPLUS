#include<iostream>
using namespace std ;
class complex
{
    private:
        int real ;
        int imag ;
    public:
        complex(int,int) ;
		complex(){}
        friend complex operator +(complex const &  , complex const &) ;
        void print() ;
};

complex::complex(int r , int i)
{
    real =r , imag=i ;
}

complex operator +(complex const & c1 , complex const & c2)
{
    complex temp ;
    temp.real = c1.real + c2.real ;
    temp.imag = c1.imag + c2.imag ;
    return temp ;
}

void complex::print()
{
    cout<<real<<"+"<<imag<<"i" ;
}

int main()
{
    complex com1(12,14);
    complex com2(13,17);
    complex com3 = com1 + com2 ;
    com3.print() ;
    return 0 ;
}