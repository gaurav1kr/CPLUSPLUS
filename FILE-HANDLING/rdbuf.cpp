#include <fstream>
#include <iostream>
#include <string>
 
using namespace std;
 
int main()
{
    ofstream file("cout.txt") ;
    streambuf* stream_buffer_file = file.rdbuf();
    streambuf* cout_file = cout.rdbuf() ;
    cout.rdbuf(stream_buffer_file);
    cout << "This line written to file\n hi" << endl;


    cout.rdbuf(cout_file) ;
    cout<<"bye" ;
 
 
    file.close();
    return 0;
}
