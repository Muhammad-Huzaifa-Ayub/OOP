#ifndef ParkingMeter_H
#define ParkingMeter_H

#include "ParkedCar.h"
#include <iostream>

using namespace std;

class ParkingMeter{
	
	private :
		
	ParkedCar car;
	int purchasedTime;
	
	public:
		ParkingMeter();
		ParkingMeter( ParkedCar &car , int &purchasedTime );
		void setlegalMins( int &purchasedTime );
		int getlegalMins()const;
		ParkedCar getCar()const;
	
};

#endif
