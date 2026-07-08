#include "iostream"

using namespace std;

class Algebra
{
	// Data members of the class
	int a, b;

public:

	// Default Constructor
	Algebra() : a{0}, b{0}
	{
		cout << "Default Constructor" << endl;
	}

	// Parameterized Constructor
	Algebra(int a, int b)
	{
		cout << "Parameterized Constructor" << endl;

		// If a is greater than 0, assign its value to data-member 'a';
		// otherwise, assign 0 to data-member 'a'.
		this->a = a > 0 ? a : 0;

		// If b is greater than 0, assign its value to data-member 'b';
		// otherwise, assign 0 to data-member 'b'.
		this->b = b > 0 ? b : 0;
	}

	// Copy Constructor
	Algebra(const Algebra& obj) : a(obj.a), b(obj.b)
	{
		cout << "Copy Constructor" << endl;
	}

	// Destructor
	~Algebra()
	{
		cout << "Destructor" << endl;
	}

	// Setter for data memeber a
	void setA(int a)
	{
		// If a is greater than 0, assign its value to data-member 'a';
		// otherwise, keep the current value of data-member 'a'.
		this->a = a > 0 ? a : this->a;
	}

	// Getter for data memeber a
	int getA()
	{
		return a;
	}

	// Setter for data memeber b
	void setB(int b)
	{
		// If b is greater than 0, assign its value to data-member 'b';
		// otherwise, keep the current value of data-member 'b'.
		this->b = b > 0 ? b : this->b;
	}

	// Getter for data memeber b
	int getB()
	{
		return b;
	}

	// Function to set object's data
	void setData(int a, int b)
	{
		setA(a);
		setB(b);
	}

	// Function to take input for object's data
	void input()
	{
		cout << "Enter a = ";
		cin >> a;

		cout << "Enter b = ";
		cin >> b;

		this->setA(a);
		this->setB(b);
	}

	// Function to display object's data on screen
	void print()
	{
		cout << "a = " << this->a << "\tb = " << (*this).b << endl;
	}
};

int main()
{
	//-----------------------------------------------//
	Algebra obj(1, 2);

	// Declaring a pointer of Algebra type
	Algebra* po = &obj;

	// Two ways to access members through pointer 
	(*po).print();		// Using dereference operator

	po->print();		// Using arrow operator
	//-----------------------------------------------//

	//-----------------------------------------------//
	// Creating an object of Algebra on Heap
	po = new Algebra(88, 99);

	// Two ways to access members through pointer 
	(*po).print();		// Using dereference operator

	po->print();		// Using arrow operator

	delete po;			// Free memory resources allocated on Heap
	//-----------------------------------------------//
	
	return 0;
}