#include<iostream>
#include<sstream>
#include<cstring>
#include<iomanip>
#include<limits>

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
	void DisplayBill ( int dec )
	{
		cout << "Your Bill is as follows :" << endl;
		cout << setw(7) << left << "ID" << setw(25) << left << "Name" << setw(15) << left << "Quantity" << setw(10) << left << "Unit Price" << endl;
		cout << "---------------------------------------------------------" << endl;
		cout << setw(7) << left << ID << setw(25) << left << Name << setw(15) << left << dec << setw(10) << left << Price << endl;
		cout << endl << "\t\t\t\t" <<"Total amount : Rs." <<  dec* Price << endl;
	}
	void DisplayMenu ()
	{
		cout << setw(7) << left << ID << setw(25) << left << Name << setw(15) << left << Quantity << setw(10) << left << Price << endl;
	}
};

void clearInput()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main()
{
	int n = 0;
	cout << "How many SaleItems you want to create : ";
	cin >> n; cin.ignore(); cout << endl;
	
	SaleItem *items = new SaleItem[n];
	
	for ( int i = 0; i < n; i++ )
	{
		cout << "Enter details of SaleItem # " << i+1 << " : ";
		char line[200];
		cin.getline(line, sizeof(line));

        char* token = strtok(line, ",");  //        string tokenizer       It cuts a string into pieces based on a separator.
        int id = atoi(token);

        token = strtok(NULL, ",");
        char name[41];
        strncpy(name, token, 40);
        name[40] = '\0';

        token = strtok(NULL, ",");
        int qty = atoi(token);

        token = strtok(NULL, ",");
        double price = atof(token);

		items[i].setID( id );
		items[i].setName( name );
		items[i].setQuantity( qty );
		items[i].setPrice( price );	
	} cout << endl;
	
	while ( true )
	{
		cout << "              Menu" << endl;
		for ( int i = 0; i < n; i++ )
		{
			items[i].DisplayMenu();
		} cout << endl;
		
		int id = 0, qty = 0;
		cout << "Enter the ID of item that you want to buy ( -1 to to exit ) : ";
		cin >> id;
		if ( id == -1 )
		{
			cout << endl << "Bye Bye!!" << endl;
			break;
		}
		int index = -1;
		for ( int i = 0; i < n; i++ )
		{
			if ( items[i].getID() == id )
			{
				index = i;
				break;
			}
		}
		if ( index == -1 )
		{
			cout << endl << "Invalid SaleItem ID" << endl << endl << endl;
			continue;
		}
		cout << "Enter the Quantity you want to buy : ";
		cin >> qty;
		if ( qty <= 0 || qty > items[index].getQuantity() )
		{
			cout << endl << "Invalid SaleItem Quantity\nAvailable : " << items[index].getQuantity() << endl << endl << endl;
			continue;
		}
		cout << endl << endl;
		
		items[index].DecrementQuantity( qty );
		items[index].DisplayBill( qty );
		cout << endl;
		
		cout << "Press any key to return to menu : ";
        clearInput(); //                                   or    cin.ignore(1000, '\n');
        cin.get();
	}
	

	delete[] items;
	
	return 0;
}


/*Write a menu based program using the SaleItem class. Your program should ask the user that how many 
SaleItems he/she wants to create. Then, it should dynamically allocate an array of SaleItems. Then, the program 
should ask the user to enter the values of all attributes for each SaleItem object (see the input format in the 
following sample run). 
After that a menu should be displayed to the user, showing the ID, Name, Quantity, and Price of each item. The user 
should be able to select (buy) any one item by specifying its ID and the quantity that he/she needs to buy. After that, 
the program should display the bill of the user (see the output format in the following sample run).  
Make sure that your program decrements the quantity of the SaleItem which was bought by the user. After displaying 
the bill the user should be asked to press any key to return back to the menu. The program should eventually terminate 
when the user enters -1 at the menu. At the end, make sure that all the dynamically allocated memory is properly 
deallocated. 
Note: In the following sample run, text that is shown in red is entered by the user.

901,Tuc Biscuits,150,15
808,Lays Chips,100,20
850,Dairy Milk Choc,200,10


*/