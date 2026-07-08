#ifndef  RoomDimension_H
#define  RoomDimension_H

#include "FeetInches.h"
#include<iostream>

using namespace std;

class  RoomDimension{
	
	private :
		
		FeetInches length;
		FeetInches width;
	
	public:
		
	void setFeetLength(int &f);
    void setInchesLength(int &i);
    int getFeetLength() const;
    int getInchesLength() const;
    
    void setFeetWidth(int &f);
    void setInchesWidth(int &i);
    int getFeetWidth() const;
    int getInchesWidth() const;

    RoomDimension();
    RoomDimension( FeetInches &length, FeetInches &width );
    float getArea() const;
    void display()const;
    
};


#endif 


