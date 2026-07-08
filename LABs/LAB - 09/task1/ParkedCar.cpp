#include "ParkedCar.h"

ParkedCar::ParkedCar()
{
	this->make = "";
	this->model =  "";
	this->color = "";
	this->licenseNo = "";
	this->parkedMins = 0;
}

ParkedCar::ParkedCar( string &make, string &model, string &color, string &licenseNo, int &parkedMins )
{
    this->make = make;
	this->model =  model;
	this->color = color;
	this->licenseNo = licenseNo;
	this->parkedMins = parkedMins;
}

string ParkedCar::getmake()const
{
	return this->make;
}

string ParkedCar::getmodel()const
{
	return this->model;
}

string ParkedCar::getcolor()const
{
	return this->color;
}

string ParkedCar::getlicenseNo()const
{
	return this->licenseNo;
}

int ParkedCar::getparkedMins()const
{
	return this->parkedMins;
}


