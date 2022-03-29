#include<iostream>
#include<thread>
#include<chrono>
#include<algorithm>

using namespace std ;
using namespace std::chrono ;
typedef unsigned long long ull ;

ull os = 0 ;
ull es = 0 ;
ull total = 0 ;

class EvenSum
{
    public:
       void operator()(ull start , ull end) 
       {
            for(ull i=start;i<=end;i++)
            {
                if (!(i & 1))
                {
                    es += i ;
                }
            }
       }
};


class OddSum
{
    public:
       void operator()(ull start , ull end) 
       {
            for(ull i=start;i<=end;i++)
            {
                if (i & 1)
                {
                    os += i;
                }
            }
       }
};

class Sum
{
    public:
       void operator()(ull start , ull end) 
       {
            for(ull i=start;i<=end;i++)
            {
                total += i;
            }
       }
};

int main()
{
    ull start = 0 ;
    ull end = 1900000000 ;
    auto startTime = high_resolution_clock::now() ;
    thread t1(EvenSum() ,start,end) ;
    thread t2(OddSum() ,start,end) ;
    thread t3(Sum() ,start,end) ;
    t1.join() ;
    t2.join() ;
    t3.join() ;

    auto endTime = high_resolution_clock::now() ;
    cout<<es<<"\n"<<os<<"\n"<<total ;
    auto duration = duration_cast<microseconds>(endTime - startTime) ;

    cout<<"Sec : "<<duration.count()/1000000<<"\n" ;
    return 0 ;
}
