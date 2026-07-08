#include<iostream>
#include<string>

using namespace std;

int main()
{
	int arr[5];
	cout << "the address of first index of arr[5] is : " << &arr << endl;
	int *p = arr;
	cout << "enter 5 integers for arr[5] : ";
	for ( int i = 0; i < 5; i++ )
	{
		cin >> *( p + i );
	}
	cout << "the addresses and contents of arr[5] are given as : " << endl;
	for ( int j = 0; j < 5; j++ )
	{
		cout << "the address of arr[" << j << "] is : " << ( p + j ) << endl;
		cout << "the content of arr[" << j << "] is : " << *( p + j ) << endl;
	}
	
	cout << endl << endl << endl;
	
	char char_arr[5];
	cout << "the address of first index of char_arr[5] is : " << (void*)&char_arr[0] << endl;
	char *char_ptr = char_arr;
	cout << "enter 5 characters for char_arr[5] : ";
	for ( int i = 0; i < 5; i++ )
	{
		cin >> *( char_ptr + i );
	}
	cout << "the addresses and contents of char_arr[5] are given as : " << endl;
	for ( int j = 0; j < 5; j++ )
	{
		cout << "the address of char_arr[" << j << "] is : " << (void*)( char_ptr + j ) << endl;
		cout << "the content of char_arr[" << j << "] is : " << *( char_ptr + j ) << endl;
	}
	
	cout << endl << endl << endl;
	
	double double_arr[5];
	cout << "the address of first index of double_arr[5] is : " << &double_arr[0] << endl;
	double *double_ptr = double_arr;
	cout << "enter 5 double no.s for double_arr[5] : ";
	for ( int i = 0; i < 5; i++ )
	{
		cin >> *( double_ptr + i );
	}
	cout << "the addresses and contents of double_arr[5] are given as : " << endl;
	for ( int j = 0; j < 5; j++ )
	{
		cout << "the address of double_arr[" << j << "] is : " << ( double_ptr + j ) << endl;
		cout << "the content of double_arr[" << j << "] is : " << *( double_ptr + j ) << endl;
	}
	 
	 
	return 0;
}