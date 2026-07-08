#include<iostream>
#include<string>

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
		cout << "Date is :  "<< day <<"/" << month << "/" << year << endl;
	}
};

int main()
{
	int d = 0,m = 0 ,y = 0;
	cout << "Enter Day/Month/Year in integers : ";
	cin >> d >> m >> y;  
	
	Date d1;
	d1.setDay( d );
	d1.setMonth( m );
	d1.setYear( y );
	
	cout << "Date is : " << d1.getDay(  ) << endl;
	cout << "Month is : " << d1.getMonth(  ) << endl;
	cout << "Year is : " << d1.getYear(  ) << endl;
	
	cout << endl << endl;
	
	d1.DisplayDate();
	
	return 0;
}