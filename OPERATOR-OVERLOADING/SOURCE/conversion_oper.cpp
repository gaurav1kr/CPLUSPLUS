#include <iostream>
#include <cmath>
  
using namespace std;
  
class Complex
{
private:
    double real;
    double imag;
  
public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i)
    {}
  
    double mag()
    {
        return getMag();
    }
  
    operator double ()
    {
        return getMag();
    }

  
private:
    double getMag()
    {
        return sqrt(real * real + imag * imag);
    }
};
  
int main()
{
    Complex com(3.0, 4.0);
    cout << com << endl;
}

