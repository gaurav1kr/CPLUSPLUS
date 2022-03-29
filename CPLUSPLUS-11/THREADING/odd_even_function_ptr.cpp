#include<iostream>
#include<thread>
#include<chrono>
#include<algorithm>

using namespace std ;
using namespace std::chrono ;

unsigned long long os = 0 ;
unsigned long long es = 0 ;
unsigned long long total = 0 ;

void EvenSum(unsigned long long start , unsigned long long end)
{
    for(unsigned long long i=start;i<=end;i++)
    {
        if (!(i & 1))
        {
            es += i ;
        }
    }
}


void OddSum(unsigned long long start , unsigned long long end)
{
    for(unsigned long long i=start;i<=end;i++)
    {
        if (i & 1)
        {
            os += i;
        }
    }
}

void Sum(unsigned long long start , unsigned long long end)
{
    for(unsigned long long i=start;i<=end;i++)
    {
            total += i;
    }
}

int main()
{
    unsigned long long start = 0 ;
    unsigned long long end = 1900000000 ;
    auto startTime = high_resolution_clock::now() ;
    thread t1(EvenSum ,start,end) ;
    thread t2(OddSum,start,end) ;
    thread t3(Sum,start,end) ;
    t1.join() ;
    t2.join() ;
    t3.join() ;
#if 0
    EvenSum(start,end) ;
    OddSum(start,end) ;   // execution time is apporx 17 seconds. If we apply the threads , the execution time will be approx 10 seconds 
    Sum(start,end) ;
#endif
    auto endTime = high_resolution_clock::now() ;
    cout<<es<<"\n"<<os<<"\n"<<total ;
    auto duration = duration_cast<microseconds>(endTime - startTime) ;

    cout<<"Sec : "<<duration.count()/1000000<<"\n" ;
    return 0 ;
}
