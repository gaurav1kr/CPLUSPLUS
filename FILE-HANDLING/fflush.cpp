#include<iostream>
#include<ios>    
#include<limits>
using namespace std;
 
int main()
{
    int a;
    char str[80];
     
    cin >> a;
     
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
     
    cin.getline(str,80);
     
    cout << a << endl;
     
    cout << str << endl;
 
    return 0;
}
