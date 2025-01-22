//Below program will be compiled with C++17 only. Below are the steps for it's compilation :- 
//1. Get the boost path (It might be in /opt or /usr)
//2. Compile it with include path - g++ -std=c++17 -I/opt/homebrew/Cellar/boost/1.87.0/include boost1.cpp -o boost1 -g 
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using namespace std;
  
int128_t boost_product(long long A, long long B)
{
    int128_t ans = (int128_t) A * B;
    return ans;
}
  
int main()
{
    long long first = 98745636214564698;
    long long second=7459874565236544789;
    cout << "Product of "<< first << " * "
         << second << " = \n"
         << boost_product(first,second) ;
    return 0;
}
