#include<iostream>
#include<algorithm>
#include "Observer.h"

using namespace std;


// -1 0 1

void Car::notify()
{
	for (int i = 0; i < observerList.size(); ++i)
	{
		observerList[i]->update();
	}
}

int Car::getPosition()
{
	return position;
}

void Car::setPosition(int newPosition)
{
	position = newPosition;
	notify();
}

void Car::attach(Observer* obs)
{
	observerList.push_back(obs);
}

void Car::detach(Observer* obs)
{
	observerList.erase(remove(observerList.begin(), observerList.end(), obs), observerList.end());
}

Observer::Observer(Car *car)
{
	_car = car;
	_car->attach(this);
}

Car* Observer::getCar()
{
	return _car;
}

LeftObserver::LeftObserver(Car* car) : Observer(car) {}

void LeftObserver::update()
{
	int pos = getCar()->getPosition();
	if (pos < 0)
	{
		cout << "left side" << "\n";
	}
}

RightObserver::RightObserver(Car* car) : Observer(car) {}

void RightObserver::update()
{
	int pos = getCar()->getPosition();
	if (pos > 0)
	{
		cout << "right side" << "\n";
	}
}

MiddleObserver::MiddleObserver(Car* car) : Observer(car) {}

void MiddleObserver::update()
{
	int pos = getCar()->getPosition();
	if (pos == 0)
	{
		cout << "running in middle" << "\n";
	}
}
int main()
{
	Car* car = new Car();
	LeftObserver leftObserver(car);
	RightObserver rightObserver(car);
	MiddleObserver middleObserver(car);

	cout << "Hit left right button to drive a car in your city!! Press Esc to close" << "\n";
	char pressedButton;
	bool breakLoop = false;

	while (breakLoop == false)
	{
		cin >> pressedButton;
		switch (pressedButton)
		{
		case 108:
			car->setPosition(-1);
			break;
		case 99:
			car->setPosition(0);
			break;
		case 114:
			car->setPosition(1);
			break;
		case 98:
			breakLoop = true;
			break;
		default:
			cout << "Please drive carefully" << "\n";
			break;
		}
	}
	cout << "Bye.." << "\n";
	return 0 ;
}
