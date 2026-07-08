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

	// Setter for data member a
	void setA(int a)
	{
		// If a is greater than 0, assign its value to data-member 'a';
		// otherwise, keep the current value of data-member 'a'.
		this->a = a > 0 ? a : this->a;
	}

	// Getter for data member a
	int getA()
	{
		return a;
	}

	// Setter for data member b
	void setB(int b)
	{
		// If b is greater than 0, assign its value to data-member 'b';
		// otherwise, keep the current value of data-member 'b'.
		this->b = b > 0 ? b : this->b;
	}

	// Getter for data member b
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

	// Function to add the current object's data with another object's data
	// Parameters:
	// - obj: The Algebra object whose data will be added to the current object's data
	// Returns: A new Algebra object containing the sum of the two objects' data
	Algebra add(const Algebra& obj)
	{
		return Algebra(this->a + obj.a, this->b + obj.b);
	}

	// Function to compare the current object's data with another object's data
	// Parameters:
	// - obj: The Algebra object whose data will be compared to the current object's data
	// Returns: true if both objects contain same data, false otherwise
	bool equal(const Algebra& obj)
	{
		return (this->a == obj.a && this->b == obj.b);
	}
};

int main()
{
	Algebra o1(1, 2), o2{3, 4};

	Algebra r = o1.add(o2);

	r.print();	//4	6
	
	if(o1.equal(o2))
		cout << "Objects are Equal" << endl;
	else
		cout << "Objects are Not Equal" << endl;

	return 0;
}