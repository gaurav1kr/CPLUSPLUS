#include<iostream>
using namespace std;
#define MAX1 3
class ops
{
		private:
			int arr[MAX1] ;
		
		public:
			ops(int i , int j  , int k) : arr {i , j , k} {}
			
			
			int operator []( int n)
			{
					return arr[n] ;
			}
			
};

int main()
{
		ops obj1(12,13,14) ;
		cout<<obj1[2] ;
		return 0 ;
}