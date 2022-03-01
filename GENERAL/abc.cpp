#include<iostream>
using namespace std ;
class Test
{
    public:
        Test();
        ~Test() ;
};

Test::Test()
{
    cout<<"Constructor called\n" ;
}

Test::~Test()
{
    cout<<"Destructor called\n" ;
}
int main()
{
    static Test t1 ;
    exit(0) ;
//    return 0 ;
}
