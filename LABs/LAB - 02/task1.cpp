#include<iostream>
#include<string>

using namespace std;

int main()
{
	int j = 786;
	cout << "the address of j is : " << &j << endl;
	cout << "the data stored in j is : " << j << endl;
	int *p = &j;
	cout << "the address of p is : " << &p << endl;
	cout << "the data stored in p is : " << p << endl;
	cout << "incrementing the value of j using dereference operator : " << ++(*p) << endl;
	
	cout << endl << endl << endl;
	
	char i = 'a';
	cout << "the address of i is : " << (void*)&i << endl;
	cout << "the data stored in i is : " << i << endl;
	char *char_ptr = &i;
	cout << "the address of char_ptr is : " << &char_ptr << endl;
	cout << "the data stored in char_ptr is : " << (void*)char_ptr << endl;
	cout << "incrementing the value of i using dereference operator : " << ++(*char_ptr) << endl;
	
	cout << endl << endl << endl;
	
	double k = 786.786;
	cout << "the address of k is : " << &k << endl;
	cout << "the data stored in k is : " << k << endl;
	double *double_ptr = &k;
	cout << "the address of double_ptr is : " << &double_ptr << endl;
	cout << "the data stored in double_ptr is : " << double_ptr << endl;
	cout << "incrementing the value of k using dereference operator : " << ++(*double_ptr) << endl;
	
	
	return 0;
}