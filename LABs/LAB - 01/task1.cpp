#include<iostream>
#include<string>

using namespace std;

bool addArrays(int arr1[],int s1,int arr2[],int s2)
{
	bool flag;
	if ( s1 == s2 )
	{
		for ( int i = 0; i < s1; i++ )
		{
			arr1[i] += arr2[i];
		}
		flag = true;
	}
	else flag = false;
	
	return flag;
}

const int col = 3;

bool addArrays1(int r1,int c1,int array1[][col],int r2,int c2,int array2[][col])
{
	bool flag;
	if ( r1 == r2 && c1 == c2 )
	{
		for ( int i = 0; i < r1; i++ )
		{
			for ( int j = 0; j < c1; j++ )
			{
				array1[i][j] += array2[i][j];
			}
		}
		flag = true;
	}
	else flag = false;
	
	return flag;
}

int main()
{
	int s1 = 5;
	int s2 = 5;
	int arr1[s1] = {3,4,6,7,6};
	int arr2[s2] = {6,4,3,8,7};
	
	cout << "adding contents of two arrays but first checking condition ......" << endl;
	if ( addArrays(arr1,s1,arr2,s2) )
	{
		cout << "two arrays are added" << endl;
	}
	else cout << "arrays not added" << endl;
	
	cout << endl << endl << endl;
	
	const int r1 = 2, c1 = 3;
	const int r2 = 2, c2 = 3;
	int array1[r1][c1] = { {1,5,6} , {8,9,3} };
	int array2[r2][c2] = { {4,7,8} , {4,7,9} };
	
	cout << "adding contents of two two-dimensional arrays but first checking condition ......" << endl;
	if ( addArrays1(r1,c1,array1,r2,c2,array2) )
	{
		cout << "two arrays are added" << endl;
	}
	else cout << "arrays not added" << endl;
	
	
	return 0;
}