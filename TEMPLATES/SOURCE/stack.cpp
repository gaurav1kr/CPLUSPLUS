#include<iostream>
using namespace std ;
#define SIZE 10
template<class T> class stack
{
    private:
        int top;
        T data[SIZE] ;
    public:
        stack() ;
        void push(T);
        T pop() ;
        bool IsEmpty() ;
        bool IsFull() ;
        T GetTop();
};

template<class T> stack<T>::stack()
{
    top = -1 ;
}

template<class T> void stack<T>::push(T elem)
{
    if(top == SIZE)
    {
        cout<<"No more insertions\n" ;
        return ;
    }
    data[++top] = elem ; 
    cout<<"Pushed Element = "<<elem<<"\n" ;
}

template<class T> T stack<T>::pop()
{
    cout<<"Popped Element = " ;
    return data[top--] ;
}

template<class T> bool stack<T>::IsEmpty()
{
    cout<<"Check stack empty condition..."<<"\n" ;
    return(top == -1)?1:0 ;
}

template<class T> bool stack<T>::IsFull()
{
    cout<<"Check stack full condition..."<<"\n" ;
    return(top >= 10)?1:0 ;
}

template<class T> T stack<T>::GetTop()
{
    return top ;
}

int main()
{
    stack<int> stk ;
    stk.push(10) ;
    stk.push(20) ;
    stk.push(30) ;
    stk.push(40) ;
    stk.push(50) ;
    stk.push(60) ;
    stk.push(70) ;
    if(stk.GetTop() >=0 )
    {
        cout<<stk.pop()<<"\n" ;
    }
    stk.push(80) ;
    stk.push(90) ;
    stk.push(71) ;
    stk.push(73) ;
    stk.push(79) ;
    stk.push(62) ;
    if(stk.GetTop() >=0 )
    {
        cout<<stk.pop() <<"\n";
    }
    if(stk.GetTop() >=0 )
    {
        cout<<stk.pop() <<"\n" ;
    }
    cout<<stk.IsFull() ;
}
