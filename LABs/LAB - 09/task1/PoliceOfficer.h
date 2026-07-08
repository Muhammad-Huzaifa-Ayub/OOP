#ifndef   PoliceOfficer_H
#define   PoliceOfficer_H

#include "ParkingMeter.h"
#include <iostream>

using namespace std;

class  PoliceOfficer{
	
	private :
		
		ParkingMeter meteredCar;
		string PoliceOfficerName;
		int badge;
	
	
	public:
		PoliceOfficer();
		PoliceOfficer( ParkingMeter &meteredCar, string &PoliceOfficerName, int &badge );
		string getPoliceOfficerName() const;
		int getbadge()const;
		bool expiredTime ()const;
		ParkingMeter getmeteredCar()const;
		
};

#endif