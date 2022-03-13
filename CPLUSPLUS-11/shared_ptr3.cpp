#include<iostream>
#include<memory>
using namespace std ;
int main()
{ 
    int *p = new int[10] ;
    shared_ptr<int> q(p) ;

    if(q.get() == p)
    {
        cout<<"sharing worked well\n" ;
    }
    if(p)
    {
        cout<<"not freed" ;
    }
    else
    {
        cout<<"freed" ;
    }
//    delete []p ;
    if(q.get() == p)
    {
        cout<<"sharing worked well" ;
    }
    else
    {
        cout<<"sharing doesnot worked" ;
    }
    return 0 ;
}
