#include <iostream>
using namespace std;

class MyClass {
    int *data;

public:
    // Constructor
    MyClass()
    {
        cout << "default Constructor called" << endl;
	data = new int ;
    }

    MyClass(int value) {
        data = new int(value);  // Allocate memory dynamically
        cout << "Copy Constructor called" << endl;
    }

    // Default copy constructor (deep copy)
    MyClass(const MyClass &other) 
    {
	data = new int(*(other.data)) ;
    }


    // Default copy constructor (shallow copy)
    //MyClass(const MyClass &other) = default ; //If we uncomment this line and comment above lines where we are doing deep copy, it will be a shallow copy and program will crash due to double free when destructor will be called. 

    MyClass & operator=(const MyClass & other)
    {
	cout<<"Copy Assignment operator called\n" ;
	if(this != &other)
	{
		delete data ;
		data = new int(*(other.data)) ;
	}
	return *this ;
    }
    // Destructor
    ~MyClass() {
        delete data;  // Release the memory
        cout << "Destructor called" << endl;
    }

    int getData() const {
        return *data;
    }
};

int main() {
    MyClass obj1(10);
    MyClass obj2 = obj1;  // Shallow copy (default copy constructor)
    MyClass obj3 ;
    obj3 = obj2 ;

    cout << "obj1 data: " << obj1.getData() << endl;
    cout << "obj2 data: " << obj2.getData() << endl;
    cout << "obj3 data: " << obj3.getData() << endl;

    return 0;
}
