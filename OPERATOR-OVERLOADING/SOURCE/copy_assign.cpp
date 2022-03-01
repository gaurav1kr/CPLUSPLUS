#include<iostream>
using namespace std ;
class net
{
    private:
        int *ptr ;
    public:
        net()
        {
            ptr = new int() ;
        }
		net(const net & net_temp)
		{
			*ptr = *(net_temp.ptr) ;
		}
		net & operator = (const net & net_temp)
		{
			*ptr = *(net_temp.ptr) ;
			return *this ;
		}
        void print_ptr()
        {
            cout<<*ptr ;
        }
        void setval(int n)
        {
            *ptr = n ;
        }
        int getval()
        {
            return *ptr ;
        }
};

int main()
{
    net d ;  
    d.setval(10) ;
	
	net d_copy ;
	d_copy = d ;
	
	cout<<d_copy.getval() ;
    return 0 ;
}