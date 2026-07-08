#include "ParkingMeter.h"

ParkingMeter::ParkingMeter()
{
	
}

ParkingMeter::ParkingMeter( ParkedCar &car, int &purchasedTime )
{
	this->car = car;
	this->purchasedTime = purchasedTime;
}

void ParkingMeter::setlegalMins( int &purchasedTime )
{
	this->purchasedTime = purchasedTime;
}

int ParkingMeter::getlegalMins() const
{
	return this->purchasedTime;
}

ParkedCar ParkingMeter::getCar() const
{
	return this->car;
}