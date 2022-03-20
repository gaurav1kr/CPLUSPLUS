#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;
void print(int v)
{
    cout<<v<<"\n" ;
}
int main()
{
    vector<int> v ; 
    for(int i=0;i<10;i++)
        v.push_back(i) ;

    for(auto & i : v)
    {
        cout<<i<<"\n" ;
    }

    for_each(v.begin() +3 , v.end() , [](int i){cout<<i<<"\n";}
            ) ;
    return 0 ;
}
