#include<iostream>
#include<string>

using namespace std;

const int S = 3;

int main()
{
	int matrix[S][S] = { {1,2,3} , {4,5,6} , {7,8,9} };
	
	int temp[S][S] = {0};
	
	int x = S-1;
	for ( int i = 0; i < S; i++ )
	{
		for ( int j = 0; j < S; j++ )
		{
			temp[j][x] = matrix[i][j];
		}
		x--;
	}
	cout << endl << endl << endl << endl;
	for ( int i = 0; i < S; i++ )
	{
		for ( int j = 0; j < S; j++ )
		{
			cout << temp[i][j] << "  ";
		}
		cout << endl;
	}
	
	return 0;
}