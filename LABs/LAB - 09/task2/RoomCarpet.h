#ifndef  RoomCarpet_H
#define  RoomCarpet_H

#include<iostream>
#include "RoomDimension.h"

using namespace std;

class  RoomCarpet{
	
	private :
		
		RoomDimension roomSize;
		float costPerSquareFoot;
		
	public:
		
		void setroomSize( RoomDimension &roomSize );
		RoomDimension getroomSize()const;
		int getcostPerSquareFoot()const;
		void setcostPerSquareFoot( float &costPerSquareFoot );
		RoomCarpet( RoomDimension &roomSize, float &costPerSquareFoot );
		float getcostofcarpet( RoomDimension &roomSize, float &costPerSquareFoot );
		void RoomCarpetDisplay()const;
};


#endif 
