#include<iostream>
#include<string>

using namespace std;

int main()
{
	
	int arr[9] = {8,12,-7,5,-1,-2,8,-3,6};
	
	int temp[9] = {0};
	
	int i = 0, j = 8, k = 0;
	while ( i < 9)
	{
		if ( arr[i] < 0)
		{
			temp[k] = arr[i];
			k++;
		}
		else 
		{
			temp[j] = arr[i];
			j--;
		}
		i++;	
	}
	
	for ( int h = 0; h < 8; h++ )
	{
		cout << temp[h] << ",";
	}
	
	return 0;
}