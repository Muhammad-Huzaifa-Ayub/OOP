#ifndef ParkedCar_H
#define ParkedCar_H

#include <iostream>
#include<cmath>

using namespace std;

class ParkedCar{
	
	private :
		
	string make;
	string model;
	string color;
	string licenseNo;
	int parkedMins;
	
	public:
		ParkedCar();
		ParkedCar( string &make, string &model, string &color, string &licenseNo, int &parkedMins);
		string getmake()const;
		string getmodel()const;
		string getcolor()const;
		string getlicenseNo()const;
		int getparkedMins()const;
	
};

#endif