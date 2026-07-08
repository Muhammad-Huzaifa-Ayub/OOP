#include<iostream>
#include<iomanip>

using namespace std;

class Date{
	
	private : 
	
	int day;
	int month;
	int year;
	
	public :
	Date ()
	{
		day = 0;
		month = 0;
		year = 0;
	}
	Date ( int d, int m, int y )
	{
		day = d;
		month = m;
		year = y;
	}
	void setDay ( int d )
	{
		day = d;
	}
	void setMonth ( int m )
	{
		month = m;
	}
	void setYear ( int y )
	{
		year = y;
	}
	int getDay ( ) const
	{
		return day;
	}
	int getMonth ( ) const
	{
		return month;
	}
	int getYear ( ) const
	{
		return year;
	}
	void DisplayDate ( )
	{
		cout << "Date is :  " << setw(2) << setfill('0') << day <<"/" << setw(2) << setfill('0') << month << "/" << year << endl;
	}
};

int main()
{
	int d = 0,m = 0 ,y = 0, n = 0;
	cout << "Enter Day/Month/Year in integers : ";
	//cin >> d >> m >> y;  
	
	Date d1;
	d1.setDay( 15 );
	d1.setMonth( 3 );
	d1.setYear( 2016 );
	
	cout << "Date is : " << d1.getDay(  ) << endl;
	cout << "Month is : " << d1.getMonth(  ) << endl;
	cout << "Year is : " << d1.getYear(  ) << endl;
	
	cout << endl << endl;
	
	d1.DisplayDate();
	cout << endl << endl;
	
	Date dates[5];
	dates[0] = Date(25, 12, 1876);
    dates[1] = Date(9, 11, 1877);
    dates[2] = Date(21, 4, 1938);
    dates[3] = Date(14, 8, 1947);
    dates[4] = Date(11, 9, 1948);
	
	for ( int i = 0; i < 5; i++ )
	{
		dates[i].DisplayDate();
	}
	cout << endl << endl << endl; 
	
	cout << "Enter no. of Dates you want to create : ";
	cin >> n;
	Date *newDate = new Date[n];
	
	for ( int i = 0; i < n; i++ )
	{
		cout << "Enter Day/Month/Year in integers : ";
		cin >> d >> m >> y;  
		newDate[i].setDay( d );
		newDate[i].setMonth( m );
		newDate[i].setYear( y );
	}
	cout << endl << endl;
	for ( int i = 0; i < n; i++ )
	{
		newDate[i].DisplayDate();
	}
	
	delete[] newDate;
	
	return 0;
}