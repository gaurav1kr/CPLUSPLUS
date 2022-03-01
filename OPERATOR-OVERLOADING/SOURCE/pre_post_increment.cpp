#include<iostream>
using namespace std ;

class ops
{
	  private:
			int val ;
	  public:
			ops();
			ops(int);
			ops operator ++() ;
			ops operator++(int) ;
			void print();
};

ops::ops()
{
	
}

ops::ops(int v)
{
		val = v;
}

ops ops::operator ++(int)
{
	 return (val++) ;
}

ops ops::operator ++()
{
	 val = val + 1 ;
	 return(val) ;
}

void ops::print()
{
	 cout<<val<<"\n" ;
}

int main()
{
		ops obj1(15) ;
		ops obj_temp = obj1++ ;
		
		obj_temp.print() ;
		
		++obj1 ;
		obj1.print() ;
		return 0 ;
}