#include<iostream>
#include<string>

using namespace std;

int** createPascalTriangle ( int n )
{
	int **array = new int *[n];
	for ( int i = 0; i < n; i++ )
	{
		array[i] = new int [ i + 1 ];
		
		array[i][0] = 1;
		array[i][i] = 1;
		
		for ( int j = 1; j < i; j++ )
		{
			array[i][j] = array[i-1][j] + array[i-1][j-1];	
		}
	}
	
	return array;
}

void displayPascalTriangle ( int **array, int n )
{
	for ( int i = 0; i < n; i++ )
	{
		for ( int k = 0; k < n-i; k++ )
		{
			cout << " ";
		}
		for ( int j = 0; j < i+1; j++ )
		{
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
}

void deallocatePascalTriangle (int** array, int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[] array[i];
	}
	delete[] array;
	
	
}

int main()
{
	int rows = 0;
	cout << "Enter no. of row for pascal triangle : ";
	cin >> rows;
	
	
	int **array = createPascalTriangle ( rows );
	displayPascalTriangle ( array, rows );
	deallocatePascalTriangle ( array, rows );	
	
	return 0;
}
	
	