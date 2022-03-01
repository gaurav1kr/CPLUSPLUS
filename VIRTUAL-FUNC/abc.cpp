#include <iostream>
using namespace std;
 
class Shape
{
public:
    Shape(int l, int w):length(l),width(w){}

    virtual int get_Area()
    {
        cout << "This is call to parent class area" << endl;
          return 1;
    }
 
protected:
    int length, width;
};
 
class Square : public Shape
{
public:
    Square(int l = 0, int w = 0) : Shape(l, w) {} 
    int get_Area()
    {
        cout << "Square area: " << length * width << endl;
        return (length * width);
    }
};

class Rectangle : public Shape
{
public:
    Rectangle(int l = 0, int w = 0) : Shape(l, w) {}
    int get_Area()
    {
        cout << "Rectangle area: " << length * width
             << endl;
        return (length * width);
    }
};
 
int main(void)
{
    Shape* s;
    Square sq(5, 5); 
    Rectangle rec(4, 5); 
 
    s = &sq;
    s->get_Area();
    s = &rec;
    s->get_Area();
 
    return 0;
}
