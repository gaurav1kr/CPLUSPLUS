#include<iostream>
using namespace std ;

class complex
{
    private:
        int real;
        int imag;
    public:
        complex(int r=0 , int i=0):real(r),imag(i){}
        friend ostream & operator << (ostream & , complex &) ;
        friend istream & operator >> (istream & , complex &) ;
};

ostream & operator << (ostream & fout , complex & comp)
{
    fout<<comp.real<<"+"<<comp.imag<<"i" ;
    return fout ;
}

istream & operator >> (istream & fin , complex & comp)
{
    cout<<"Enter real";
    fin>>comp.real ;

    cout<<"Enter imag" ;
    fin>>comp.imag ;
    return fin ;
}

int main()
{
    complex comp_obj ;
    cin>>comp_obj ;
    cout<<comp_obj ;
    return 0 ;
}
