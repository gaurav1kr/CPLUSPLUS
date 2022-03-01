#include <iostream>
using namespace std;
 
int main()
{
    try
    {
       throw 10;
    }
    catch (...)
    {
        cout << "default exceptionn";
    }
    catch (int param)
    {
        cout << "int exceptionn";
    }
 
    return 0;
}
