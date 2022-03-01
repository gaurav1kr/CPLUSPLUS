#include<iostream>
using namespace std;
class B 
{ 
    public:
        virtual void print(){}
};
class D: public B 
{
    public:
        void print(){}
};
  
int main()
{
    B *b = new D;
    D *d = dynamic_cast<D*>(b);
    if(d != NULL)
        cout<<"works";
    else
        cout<<"cannot cast B* to D*";
    getchar();
    return 0;
}
