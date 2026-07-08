#ifndef  ParkingTicket_H
#define  ParkingTicket_H

#include <iostream>
#include "PoliceOfficer.h"

using namespace std;

class ParkingTicket{
	
	private :
		
	PoliceOfficer policedCar;
	
	public:
		ParkingTicket();
		ParkingTicket( PoliceOfficer &policedCar );
		void getCarDetails()const;
		int getFine()const;
		void getPoliceOfficerDetails()const;
		
};

#endif