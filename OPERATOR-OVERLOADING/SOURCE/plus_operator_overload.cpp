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
        complex operator +(complex const & ) ;
        void print() ;
};

complex::complex(int r , int i)
{
    real =r , imag=i ;
}

complex complex::operator +(complex const &c2)
{
    complex temp ;
    temp.real = this->real + c2.real ;
    temp.imag = this->imag + c2.imag ;
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
