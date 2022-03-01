#include<iostream>
using namespace std ;
template<class T>

class Operations
{
    private:
        T num1 ;
        T num2 ;
    public:
        Operations(T temp1 , T temp2) : num1(temp1) , num2(temp2){}
        T max1()
        {
            cout<<"Max = ";
            return (num1>num2)?num1:num2 ;
        }
        T min1()
        {
            cout<<"Min = ";
            return (num1<num2)?num1:num2 ;
        }
        bool IsEqual()
        {
            cout<<"Equality check.. ";
            return(num1 == num2) ;
        }
};

int main()
{
    Operations<int> oper(12,14) ;
    cout<<oper.max1()<<"\n"<<oper.min1()<<"\n"<<oper.IsEqual()<<"\n";
    Operations<float> oper1(1.52,1.52) ;
    cout<<oper1.max1()<<"\n"<<oper1.min1()<<"\n"<<oper1.IsEqual()<<"\n";
    return 0 ;
}
