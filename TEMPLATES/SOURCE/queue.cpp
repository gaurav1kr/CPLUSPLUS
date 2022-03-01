/*Queue Implementation*/
#include<iostream>
#include<cstdlib>
#include<cstring>
#define SIZE 100

using namespace std;

template<class T>
class queue
{
			private:
				T *q_data ;
				int q_size;
				int q_capacity ;
				int front ;
				int rear ;
				int count;
			public:
				queue(int s = SIZE);
				void enqueue(T) ;
				void dequeue() ;
				T peek() ;
				bool is_empty();
				bool is_full() ;
				int getsize() ;
};

template<class T> queue<T>::queue(int s)
{
		q_size = s ;
		q_data = new T[q_size] ;
		rear = -1;
		front = 0 ;
		count = 0 ;
}

template<class T> void queue<T>::enqueue(T elem)
{
	 if(count >= q_size-1)
	 {
		  cout<<"Queue Full" ;
		  return ;
	 }
	 q_data[++rear] = elem ;
	 count++ ;
	 cout<<elem<<" Inserted\n" ;
}
template<class T> bool queue<T>::is_empty()
{
		if( (rear <= front) )
			return true ;
		
		return false ;
}

template<class T> bool queue<T>::is_full()
{
		if( (count == q_size)  )
			return true ;
		
		return false ;
}

template<class T> void queue<T>::dequeue()
{
	 if( is_empty())
	 {
			cout<<"Queue empty" ;
			return ;
	 }
	 cout<<q_data[front++]<<" Deleted\n" ;
	 count-- ;
}

template<class T> T queue<T>::peek()
{
		if(is_empty())
		{
			 cout<<"Queue empty" ;
			 exit(EXIT_FAILURE) ;
		}
		return q_data[front] ;
}


template<class T> int queue<T>::getsize()
{
	 return count ;
}

int main()
{
	queue<string> obj_queue(10) ;
	obj_queue.enqueue("gaurav");
	obj_queue.enqueue("neeraj");
	obj_queue.enqueue("vivek");
	obj_queue.enqueue("rachit");
	
	obj_queue.dequeue();
	obj_queue.enqueue("richa");
	cout<<"Front elelment is "<<obj_queue.peek() <<" size of queue = "<<obj_queue.getsize()<<"\n";
	obj_queue.enqueue("rachit1");
	obj_queue.enqueue("rachit2");
	obj_queue.enqueue("rachit3");
	obj_queue.enqueue("rachit4");
	obj_queue.enqueue("rachit5");
	obj_queue.enqueue("rachit6");
	obj_queue.enqueue("rachit7");
	
	return 0 ;
}





