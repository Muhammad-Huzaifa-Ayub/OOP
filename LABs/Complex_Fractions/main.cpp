#include<iostream>

#include "complex.h"
#include "fraction.h"

using namespace std;

int main()
{
	ComplexNumber n01;
	ComplexNumber n02(1,1);
	ComplexNumber n1(3,-8);
	ComplexNumber n2(7,2);
	
	cout << "n01 is : "; n01.display(); cout << endl << endl;
	cout << "n02 is : "; n02.display(); cout << endl << endl;

	ComplexNumber n3;
	n3 = n1 + n2;
	cout << "Addtion of Complex Numbers = " << endl;
	cout << "Addtion of "; n1.display(); cout << " and "; n2.display(); cout << " is : "; n3.display(); cout << endl;
	cout << endl << endl;
	
	ComplexNumber n4;
	n4 = n1 - n2;
	cout << "Subtraction of Complex Numbers = " << endl;
	cout << "Subtraction of "; n1.display(); cout << " and "; n2.display(); cout << " is : "; n4.display(); cout << endl;
	cout << endl << endl;
	
	ComplexNumber n5;
	n5 = n1 * n2;
	cout << "Multiplications of Complex Numbers = " << endl;
	cout << "Multiplication of "; n1.display(); cout << " and "; n2.display(); cout << " is : "; n5.display(); cout << endl;
	cout << endl << endl;
	
	ComplexNumber n6;
	n6 = n1 / n2;
	cout << "Division of Complex Numbers = " << endl;
	cout << "Division of "; n1.display(); cout << " and "; n2.display(); cout << " is : "; n6.display(); cout << endl;
	cout << endl << endl;
	
	return 0;
}