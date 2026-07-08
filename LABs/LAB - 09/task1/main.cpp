#include<iostream>
#include "ParkingTicket.h"

using namespace std;

int main()
{
	string make = "";
	string model = "";
	string color = "";
	string licenseNo = "";
	int parkedMins = 0;
	int purchasedTime = 0;

	cout << "Enter [Make] of Car       : ";
	cin >> make;
	cout << "Enter [Model] of Car      : ";
	cin >> model;
	cout << "Enter [Color] of Car      : ";
	cin >> color;
	cout << "Enter [LicenseNo.] of Car : ";
	cin >> licenseNo;
	cout << "Enter [ParkedMins] of Car : ";
	cin >> parkedMins;

	ParkedCar car ( make, model, color, licenseNo, parkedMins );

	cout << "Enter [Purchased Time in Mins] for Car : ";
	cin >> purchasedTime;
	ParkingMeter meteredCar ( car , purchasedTime );

	string PoliceOfficerName = "Imran Raza";
	int badge = 1011;
	PoliceOfficer policedCar( meteredCar, PoliceOfficerName, badge );
	if ( policedCar.expiredTime() )
	{
		ParkingTicket ticket( policedCar );
		cout << endl << endl;
		cout << "   === Car Details ===   " << endl;
		ticket.getCarDetails();
		cout << "   === Police Officer Details === " << endl;
		ticket.getPoliceOfficerDetails();
		cout << "   === Fine Details ===   " << endl;
		cout << "Fine for Parked Car is : $" << ticket.getFine() << ".00" << endl;
	}
	else
	{
		cout << "Parked Car has No Fine." << endl;
	}

	return 0;
}