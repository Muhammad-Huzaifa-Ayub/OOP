
#include "RoomDimension.h"


void RoomDimension::setFeetLength(int &f)
{
    this->length.setFeet(f);
}

void RoomDimension::setInchesLength(int &i)
{
    this->length.setInches(i);
}

int RoomDimension::getFeetLength() const
{
    return this->length.getFeet();
}

int RoomDimension::getInchesLength() const
{
    return this->length.getInches();
} 
    
void RoomDimension::setFeetWidth(int &f)
{
    this->width.setFeet(f);
}

void RoomDimension::setInchesWidth(int &i)
{
    this->width.setInches(i);
}

int RoomDimension::getFeetWidth() const
{
    return this->width.getFeet();
}

 int RoomDimension::getInchesWidth() const
{
    return this->width.getInches();
}

RoomDimension::RoomDimension()
{

}

RoomDimension::RoomDimension( FeetInches &length, FeetInches &width )
{
   this->length = length;
   this->width = width;
}

float RoomDimension::getArea() const
{
    return this->length.toFeet() * this->width.toFeet();
}

void RoomDimension::display()const
{
	cout << "Length of Room : " << length << endl;
	cout << "Width of Room  : " << width << endl;
}
        