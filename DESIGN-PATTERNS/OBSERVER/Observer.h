#include<vector>
using namespace std ;

class Car ;

class Observer
{
private:
	Car* _car;
public:
	Observer(Car* car);
	virtual void update() = 0;

protected:
	Car* getCar() ;
};

class LeftObserver : public Observer
{
public:
	LeftObserver(Car* car); 
	void update();
};

class RightObserver : public Observer
{
public:
	RightObserver(Car* car); 
	void update();
};

class MiddleObserver : public Observer
{
public:
	MiddleObserver(Car* car);
	void update();
};

class Car
{
	private:
		int position;
		vector<class Observer*> observerList;
		
	public:
		void notify() ;
		int getPosition() ;
		void setPosition(int);
		void attach(Observer* obs);
		void detach(Observer* obs);
};
