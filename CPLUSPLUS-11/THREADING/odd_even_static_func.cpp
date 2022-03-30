#include<iostream>
#include<thread>
#include<chrono>
#include<algorithm>

using namespace std ;
using namespace std::chrono ;

unsigned long long os = 0 ;
unsigned long long es = 0 ;
unsigned long long total = 0 ;

class Sum 
{
    public:
    static void EvenSum(unsigned long long start , unsigned long long end)
    {
        for(unsigned long long i=start;i<=end;i++)
        {
            if (!(i & 1))
            {
                es += i ;
            }
        }
    }

    static void OddSum(unsigned long long start , unsigned long long end)
    {
        for(unsigned long long i=start;i<=end;i++)
        {
            if (i & 1)
            {
                os += i;
            }
        }
    }

};

int main()
{
    unsigned long long start = 0 ;
    unsigned long long end = 1900000000 ;
    Sum s1 ;
    auto startTime = high_resolution_clock::now() ;
    thread t1(&Sum::EvenSum , start,end) ;
    thread t2(&Sum::OddSum , start,end) ;
    t1.join() ;
    t2.join() ;

    auto endTime = high_resolution_clock::now() ;
    cout<<es<<"\n"<<os<<"\n"<<total ;
    auto duration = duration_cast<microseconds>(endTime - startTime) ;

    cout<<"Sec : "<<duration.count()/1000000<<"\n" ;
    return 0 ;
}
