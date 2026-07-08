#include<iostream>
#include<string>

using namespace std;

int getTotal( int r, int c, int data[][6])
{
	int sum = 0;
	for ( int i = 0; i < r; i++ )
	{
		for ( int j = 0; j < c; j++ )
		{
			sum += data[i][j];
		}
	}
	return sum;
}


void getRowTotal( int r, int c, int data[][6])
{
	for ( int i = 0; i < r; i++ )
	{
		int sum = 0;
		for ( int j = 0; j < c; j++ )
		{
			sum += data[i][j];
		}
		cout << "The sum of " << i+1 << " th row is : " << sum << endl;
	}
	return;
}


void getColTotal( int r, int c, int data[][6])
{
	for ( int i = 0; i < c; i++ )
	{
		int sum = 0;
		for ( int j = 0; j < r; j++ )
		{
			sum += data[j][i];
		}
		cout << "The sum of " << i+1 << " th column is : " << sum << endl;
	}
	return;
}


void getHighestInRow( int r, int c, int data[][6])
{
	for ( int i = 0; i < r; i++ )
	{
		int max = data[0][i];
		for ( int j = 0; j < c; j++ )
		{
			if ( max < data[i][j] )
			{
				max = data[i][j];
			}
		}
		cout << "The highest value in " << i+1 << " th row is : " << max << endl;
	}
	return;
}

void getLowestInRow( int r, int c, int data[][6])
{
	for ( int i = 0; i < r; i++ )
	{
		int max = data[0][i];
		for ( int j = 0; j < c; j++ )
		{
			if ( max > data[i][j] )
			{
				max = data[i][j];
			}
		}
		cout << "The lowest value in " << i+1 << " th row is : " << max << endl;
	}
	return;
}

int main()
{
	const int r = 3, c = 6;
	int data[r][c] = { {1,7,3,8,2,2} , {3,7,3,8,6,8} , {2,7,9,5,2,8} };
	cout << "The sum of all values in the 2D array is : " << getTotal(r,c,data) << endl;
	cout << "The average of all values in the 2D array is : " << (float)getTotal(r,c,data) / (3*6) << endl;
	cout << endl << endl << endl;
	getRowTotal(r,c,data);
	cout << endl << endl << endl;
	getColTotal(r,c,data);
	cout << endl << endl << endl;
	getHighestInRow(r,c,data);
	cout << endl << endl << endl;
	getLowestInRow(r,c,data);
	cout << endl << endl << endl;

	return 0;
}