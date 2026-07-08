#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main()
{
	/*int *arr = nullptr;
	int count = 0; 
	int temp = 0;
	
	ifstream input("data.txt");
	
	while ( input >> temp )
	{
		int *newArr = new int [ count + 1];
		
		for ( int i = 0; i < count; i++ )
		{
			newArr[i]  = arr[i];
		}
		
		newArr[count++] = temp;
		delete [] arr;	
		
		arr = newArr;	
	}
	input.close();
	
	cout << "The number of counts in the file is : " << count << endl;*/
	
	
	
	/*ofstream out("data.txt");
	for ( int i = 1; i <= 555; i++ )
	{
		out << i << " ";
	}
	out.close();*/
	
	
	int count = 0;
	int temp = 0;
	ifstream input("data.txt");
	
	while ( input >> temp )
	{
		count++;
	}
	input.close();
	
	cout << "count is : " << count << endl;
	
	return 0;
}