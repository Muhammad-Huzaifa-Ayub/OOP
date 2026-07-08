#include<iostream>
#include<cstring>
#include<iomanip>

using namespace std;

class SaleItem{
	
	private : 
	
	int ID;
	char Name[41];
	int Quantity;
	double Price;
	
	public : 
	
	SaleItem()
	{
		ID = 0;
		Name[41];
		Quantity = 0;
		Price = 0;
	}
	void setID ( int id )
	{
		ID = id;
	}
	void setName( const char* name )
	{
		strcpy(Name,name);
	}
	void setQuantity ( int q )
	{
		Quantity = q;
	}
	void setPrice ( int p )
	{
		Price = p;
	}
	int getID (  ) const
	{
		return ID;
	}
	const char* getName(  )
	{
		return Name;
	}
	int getQuantity (  ) const
	{
		return Quantity;
	}
	int getPrice (  ) const
	{
		return Price;
	}
	void IncrementQuantity ( int inc )
	{
		Quantity = Quantity + inc;
	}
	void DecrementQuantity( int dec )
	{
		Quantity = Quantity - dec;
	}
	void DisplayInformation ()
	{
		cout << "Your Bill is as follows :" << endl;
		cout << setw(7) << left << "ID" << setw(25) << left << "Name" << setw(15) << left << "Quantity" << setw(10) << left << "Unit Price" << endl;
		cout << "---------------------------------------------------------" << endl;
		cout << setw(7) << left << ID << setw(25) << left << Name << setw(15) << left << Quantity << setw(10) << left << Price << endl;
		cout << endl << "\t\t\t\t" <<"Total amount : Rs." << Quantity*Price << endl;
	} 
	
	
};

int main()
{

	SaleItem s1;
	s1.setName("Mango juice");
	s1.IncrementQuantity(6);
	s1.setPrice(3);
	s1.DisplayInformation();

	return 0;
}