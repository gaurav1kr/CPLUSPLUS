#include<iostream>
#include<fstream>
using namespace std ;

int main()
{
    string str1, str2 ;
    ofstream of1("file1.txt") ;
    of1<<"hi gaurav" ;
    of1.close() ;

    ifstream if1("file1.txt") ;
    if1>>str1>>str2;

    cout<<str1<<"\t"<<str2 ;
    if1.close() ;
    return 0 ;
}
