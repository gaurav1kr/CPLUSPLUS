#include<iostream>

using namespace std ;
int main()
{
    string str ;
    int t = 4 ;
    while(t>=1)
    {
        getline(cin,str) ;
        while(str.length() == 0)
        cout<<"new :"<<str<<endl ;
        t-- ;
    }
    return 0 ;
}
