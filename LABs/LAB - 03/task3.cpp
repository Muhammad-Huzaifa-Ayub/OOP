#include<iostream>
#include<cstring>

using namespace std;

struct Item{
	char name[50];
	int quantity;
	float unitPrice;
};

struct Cart{
	Item *data;
	int noOfItems;
	int capacity;
};

void initializeCart( Cart &c, const int capacity )
{
	c.capacity = capacity;
	c.noOfItems = 0;
	
	if ( capacity > 0 )
	{
		c.data = new Item[capacity];
	}
	else c.data = nullptr;
	
}

bool addItem ( Cart &c, const Item &item )
{
	if ( c.noOfItems >= c.capacity || c.data == nullptr )
	{
		return false;
	}
	
	c.data[c.noOfItems] = item;
	
	c.noOfItems++;
	
	return true;
	
}

bool removeItem ( Cart &c, char *ItemName, int count = 1 )
{
	if ( c.noOfItems == 0 || c.data == nullptr || count <=0 )
	{
		return false;
	}
	
	int removed = 0, i = 0;
	while ( i < c.noOfItems && removed < count )
	{
		if( strcmp( c.data[i].name , ItemName ) == 0 )
		{
			for( int j = i; j < c.noOfItems - 1; j++ )
			{
				c.data[j] = c.data[j+1];
			}
			c.noOfItems--;
			removed++;
		}
		else i++;			
	}
	
	return removed > 0;
}

void checkout(const Cart &c)
{
    float total = 0;
    cout << "Items in Cart:\n";

    for(int i = 0; i < c.noOfItems; i++)
    {
        float itemTotal = c.data[i].quantity * c.data[i].unitPrice;
        total += itemTotal;

        cout << c.data[i].name << " | "
             << c.data[i].quantity << " | "
             << c.data[i].unitPrice << " | "
             << "Total: " << itemTotal << endl;
    }

    cout << "\nGrand Total: " << total << endl;
}


void resize( Cart &c, int s = 5 )
{
	int newCapacity = c.capacity + s;
	
	Item *newData = new Item[newCapacity];
	
	for ( int i = 0; i < c.noOfItems; i++ )
	{
		newData[i] = c.data[i];
	}
	
	delete[] c.data;
	
	c.data = newData;
	c.capacity = newCapacity;
}

int main()
{
	
	Cart c;
	initializeCart( c, 2 );
	
	Item item1 = {"Apple",45,2.5};
	Item item2 = {"Jam",2,7.99};
	Item item3 = {"Bread",4,3.5};
	
	addItem(c,item1);
	addItem(c,item2);
	
	checkout(c);
	cout << endl;
	
    char nameToRemove[] = "Jam";
    if(removeItem( c, nameToRemove, 1) ) cout << "Item removed successfully." << endl;
    else cout << "Item not found." << endl;
    cout << endl << endl;  
	checkout(c);
	
	resize( c, 5 );
	addItem(c,item2);
	addItem(c,item3);
	cout << endl << endl;  
	checkout(c);
	
	delete[] c.data;
	
	return 0;
}