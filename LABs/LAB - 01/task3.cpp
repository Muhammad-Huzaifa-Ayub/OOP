#include<iostream>
#include<string>

using namespace std;

int main()
{
	int arr[8] = {18,20,16,14,10,8,100,2};
	
	
	for ( int i = 0; i < 8; i++ )
	{
		for ( int j = 0; j < 8; j++ )
		{
			if( arr[i] != arr[j] && arr[i] % arr[j] == 0 )
			{
				cout << arr[i] << " " << arr[j] << " - ";
			}
		}
	}
	cout << "\b";
	
	return 0;
}