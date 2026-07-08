#include<iostream>
#include<cstring>

using namespace std;

struct Book{
	char name[50];
	char publisher[50];
	int ISBNNumber;
};

struct Library{
	Book *data;
	int noOfBooks;
	int capacity;
};

void initializeLibrary( Library &ly, const int capacity )
{
	ly.capacity = capacity;
	ly.noOfBooks = 0;
	
	if ( capacity > 0 )
	{
		ly.data = new Book[capacity];
	}
	else ly.data = nullptr;
	
}

bool addBook ( Library &ly, const Book &bo )
{
	if ( ly.noOfBooks >= ly.capacity || ly.data == nullptr )
	{
		return false;
	}
	
	ly.data[ly.noOfBooks] = bo;
	
	ly.noOfBooks++;
	
	return true;
	
}

bool removeBook ( Library &ly, char *BookName, int count = 1 )
{
	if ( ly.noOfBooks == 0 || ly.data == nullptr || count <=0 )
	{
		return false;
	}
	
	int removed = 0, i = 0;
	while ( i < ly.noOfBooks && removed < count )
	{
		if( strcmp( ly.data[i].name , BookName ) == 0 )
		{
			for( int j = i; j < ly.noOfBooks - 1; j++ )
			{
				ly.data[j] = ly.data[j+1];
			}
			ly.noOfBooks--;
			removed++;
		}
		else i++;			
	}
	
	return removed > 0;
}

void Display(const Library &ly)
{
    cout << "Books in Library : " << endl;
    for(int i = 0; i < ly.noOfBooks; i++)
    {
        cout << ly.data[i].name << " | " << ly.data[i].publisher << " | " << ly.data[i].ISBNNumber << endl;
    }
}

void resize( Library &ly, int s = 5 )
{
	int newCapacity = ly.capacity + s;
	
	Book *newData = new Book[newCapacity];
	
	for ( int i = 0; i < ly.noOfBooks; i++ )
	{
		newData[i] = ly.data[i];
	}
	
	delete[] ly.data;
	
	ly.data = newData;
	ly.capacity = newCapacity;
}

int main()
{
	
	Library ly;
	initializeLibrary( ly, 2 );
	
	Book b1 = {"Physics","Sheldon lee cooper",1989};
	Book b2 = {"C++","John Doe",1017};
	Book b3 = {"Daffodils","William words worth",1009};
	
	addBook(ly,b1);
	addBook(ly,b2);
	
	Display(ly);
	cout << endl;
	
    char nameToRemove[] = "C++";
    if(removeBook( ly, nameToRemove, 1) ) cout << "Book removed successfully." << endl;
    else cout << "Book not found." << endl;
    cout << endl << endl;  
	Display(ly);
	
	resize( ly, 5 );
	addBook(ly,b2);
	addBook(ly,b3);
	cout << endl << endl;  
	Display(ly);
	
	delete[] ly.data;
	
	return 0;
}