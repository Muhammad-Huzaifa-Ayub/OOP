
#include "RoomCarpet.h"


int RoomCarpet::getcostPerSquareFoot()const
{
	return this->costPerSquareFoot;
}

void RoomCarpet::setcostPerSquareFoot( float &costPerSquareFoot )
{
	this->costPerSquareFoot =  costPerSquareFoot;
}

void RoomCarpet::setroomSize( RoomDimension &roomSize )
{
	this->roomSize = roomSize;
}

RoomDimension RoomCarpet::getroomSize()const
{
	return this->roomSize;	
}

RoomCarpet::RoomCarpet( RoomDimension &roomSize, float &costPerSquareFoot )
{
	this->roomSize = roomSize;
	this->costPerSquareFoot = costPerSquareFoot;
}

float RoomCarpet::getcostofcarpet( RoomDimension &roomSize, float &costPerSquareFoot )
{
	return roomSize.getArea() * costPerSquareFoot;
}

void RoomCarpet::RoomCarpetDisplay() const
{
	cout << "   === Room Size & Carpet Info ===   " << endl;
	this->roomSize.display();
	cout << "Cost PerSquareFoot is : ";
	cout << this->costPerSquareFoot << endl;
}