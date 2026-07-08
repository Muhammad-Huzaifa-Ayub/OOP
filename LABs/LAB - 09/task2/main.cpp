#include<iostream>
#include "RoomCarpet.h"

using namespace std;

int main()
{
    int FL = 0, IL = 0, FW = 0, IW = 0;
    float price = 0;
    cout << "   ===== Enter RoomDimensions to calculate cost of Carpet in the Room =====   " << endl << endl;
    cout << "Enter Room Feet-Length   : ";
    cin >> FL;
    cout << "Enter Room Inches-Length : ";
    cin >> IL;
    cout << "Enter Room Feet-Width    : ";
    cin >> FW;
    cout << "Enter Room Feet-Width    : ";
    cin >> IW;
    cout << "Enter costPerSquareFoot of the Carpet : ";
    cin >> price;
    FeetInches length(FL, IL);
    FeetInches width( FW, IW );
    RoomDimension room ( length , width );
    RoomCarpet roomcarpet ( room , price );
    cout << endl << endl;
    roomcarpet.RoomCarpetDisplay();
    cout << endl << endl;
    cout << "Total cost of Carpet for Room : Rs" << roomcarpet.getcostofcarpet( room , price )  << "/-"<< endl;


    return 0;
}