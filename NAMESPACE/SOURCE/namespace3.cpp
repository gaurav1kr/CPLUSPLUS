#include <iostream>
using namespace std;
  
namespace ns1
{
    namespace ns2
    {
        namespace ns3
        {
            int var = 10;
        }
        using namespace ns3;
    }
      
    using namespace ns2;
}
  
int main()
{
    cout << ns1::ns2::var;
    return 0;
}
