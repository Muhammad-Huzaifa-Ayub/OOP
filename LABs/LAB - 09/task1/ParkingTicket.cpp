#include "ParkingTicket.h"

ParkingTicket::ParkingTicket()
{

}

ParkingTicket::ParkingTicket( PoliceOfficer &policedCar )
{
	this->policedCar = policedCar;
}

void ParkingTicket::getCarDetails() const
{
	cout << "Car's Model       : " << this->policedCar.getmeteredCar().getCar().getmodel();
	cout << endl;
	cout << "Car's Make        : " << this->policedCar.getmeteredCar().getCar().getmake();
	cout << endl;
	cout << "Car's Color       : " << this->policedCar.getmeteredCar().getCar().getcolor();
	cout << endl;
	cout << "Car's licenseNo.  : " << this->policedCar.getmeteredCar().getCar().getlicenseNo();
	cout << endl;
	cout << "Car's ParkedMins  : " << this->policedCar.getmeteredCar().getCar().getparkedMins();
	cout << endl;
}

void ParkingTicket::getPoliceOfficerDetails() const
{
	cout << "Police Officer Name       : " << this->policedCar.getPoliceOfficerName();
	cout << endl;
	cout << "Police Officer Badge No.  : " << this->policedCar.getbadge();
	cout << endl;
}

int ParkingTicket::getFine() const
{
	if ( !policedCar.expiredTime() ) return 0;

	int parked = this->policedCar.getmeteredCar().getCar().getparkedMins();
	int purchased = this->policedCar.getmeteredCar().getlegalMins();

	int illegalMinutes = parked - purchased;

	int fine = 25;
	if ( illegalMinutes > 60 )
	{
		int extraMinutes = illegalMinutes - 60;
		fine += ceil(extraMinutes / 60.0) * 10;
	}

	return fine;
}