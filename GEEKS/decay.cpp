#include<iostream>
using namespace std;
 
void fun(int (&p)[7])
{
    cout << "Modified size of array by "
            "passing by reference: ";
    cout << sizeof(p) << endl;
}
 
int main()
{
    int a[7] = {1, 2, 3, 4, 5, 6, 7,};
 
    cout << "Actual size of array is: ";
    cout << sizeof(a) <<endl;
 
    fun(a);

    return 0;
}
