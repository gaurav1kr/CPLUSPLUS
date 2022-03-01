/* vector implementation */
#include<iostream>
#include<string>
using namespace std ;
template<class T> class vector
{
    private:
        T *data;
        int size;
        int capacity ;
    public:
        vector();
        void push_back(T);
        void pop_back();
        void insert(T data , int index) ;
        int GetSize() ;
        int GetCapacity() ;
        void print();
};

template<class T> void vector<T>::print()
{
    if(size == 0)
    {
        cout<<"No elements to print" ;
        return ;
    }
    for(int loop=0;loop<size;loop++)
    {
        cout<<data[loop]<<"\t" ;
    }
    cout<<"\n" ;
}
template<class T> vector<T>::vector()
{
    data = new T[1] ;
    capacity = 1 ;
    size = 0 ;
}

template<class T> void vector<T>::push_back(T elem)
{
    if(size == capacity)
    {
        T *temp_elem = new T[2*capacity] ;
        for(int loop=0;loop<size;loop++)
        {
            temp_elem[loop] = data[loop] ;
        }
        delete []data ;
        capacity *=  2;
        data = temp_elem ;
    }
    data[size] = elem ;
    size++ ;
}

template<class T> void vector<T>::pop_back()
{
    if(size == 0)
    {
        cout<<"vector empty" ;
        return ;
    }
    cout<<data[--size]<<"   Popped back\n";
}

template<class T> int vector<T>::GetSize()
{
    return size ; 
}

template<class T> int vector<T>::GetCapacity()
{
    return capacity ;
}

int main()
{
    vector<string> vec1;
    vec1.push_back("gaurav");
    vec1.push_back("neeraj");
    vec1.push_back("rachit");
    vec1.push_back("richa");
    vec1.print();
    vec1.pop_back() ;
    vec1.print();
    cout<<"vector size is "<<vec1.GetSize()<<"\n" ;
    cout<<"vector capacity is "<<vec1.GetCapacity()<<"\n" ;
    return 0 ;
}
