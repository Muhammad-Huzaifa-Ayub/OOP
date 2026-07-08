#include "PoliceOfficer.h"

PoliceOfficer::PoliceOfficer()
{

}

PoliceOfficer::PoliceOfficer( ParkingMeter &meteredCar, string &PoliceOfficerName, int &badge )
{
	this->meteredCar = meteredCar;
	this->PoliceOfficerName = PoliceOfficerName;
	this->badge = badge;
}

bool PoliceOfficer::expiredTime()const
{
	return this->meteredCar.getCar().getparkedMins() > this->meteredCar.getlegalMins();
}

string PoliceOfficer::getPoliceOfficerName()const
{
	return this->PoliceOfficerName;
}

int PoliceOfficer::getbadge()const
{
	return this->badge;
}

ParkingMeter PoliceOfficer::getmeteredCar() const
{
	return this->meteredCar;
}
