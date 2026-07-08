#include<iostream>
#include<string>

using namespace std;

void getPosNeg( const int ar[], const int n_ar, int* pos, int n_pos, int* neg, int n_neg )
{
	int j = 0, k = 0;
	for ( int i = 0; i < n_ar; i++ )
	{
		if ( ar[i] > 0 )
		{
			pos[j] = ar[i];
			j++;
		}
		if ( ar[i] < 0 )
		{
			neg[k] = ar[i];
			k++;
		}
	}
	
	if (!n_pos == 0)
	{
		cout << "Positive number array is : ";
		for ( int i = 0; i < n_pos; i++ )
		{
			cout << pos[i] << ",";
		}
		cout << endl;
	}
	else cout << "There are no positive numbers in the array." << endl;
	
	if (!n_neg == 0)
	{
		cout << "Negative number array is : ";
		for ( int i = 0; i < n_neg; i++ )
		{
			cout << neg[i] << ",";
		}
		cout << endl;
	}
	else cout << "There are no negative numbers in the array." << endl;
	
	
	
	return;
}

int main()
{
	const int n_ar = 10;
	const int ar[n_ar] = {33,54,-764,74,-46,-563,652,-22,542,-344};
	
	
	int n_pos = 0, n_neg = 0;
	
	for ( int i = 0; i < n_ar; i++ )
	{
		if ( ar[i] < 0 )
		{
			n_neg++;
		}
		else n_pos++;
	}
	
	int* pos = new int [n_pos];
	int* neg = new int [n_neg];
	
	getPosNeg( ar, n_ar, pos, n_pos, neg, n_neg );
	
	
	delete[] pos;
	delete[] neg;

	
	return 0;
}