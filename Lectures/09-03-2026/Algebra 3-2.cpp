#include "iostream"

using namespace std;

class Algebra
{
	// Data members of the class
	int a, b;

public:

	// Default Constructor
	Algebra() : a{ 0 }, b{ 0 }
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
	int getA() const
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
	int getB() const
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
	void print() const
	{
		//this->a = 5;	Error, current object's reference is constant

		cout << "a = " << this->a << "\tb = " << (*this).b << endl;
	}

	// Function to add the current object's data with another object's data
	// Parameters:
	// - obj: The Algebra object whose data will be added to the current object's data
	// Returns: A new Algebra object containing the sum of the two objects' data
	Algebra add(const Algebra& obj)  const
	{
		return Algebra(this->a + obj.a, this->b + obj.b);
	}

	// Function to compare the current object's data with another object's data
	// Parameters:
	// - obj: The Algebra object whose data will be compared to the current object's data
	// Returns: true if both objects contain same data, false otherwise
	bool equal(const Algebra& obj)  const
	{
		return (this->a == obj.a && this->b == obj.b);
	}

	/**
	 * @brief Searches for a specific combination of 'a' and 'b' values within an array of Algebra objects.
	 *
	 * @param ar The array of Algebra objects to search within.
	 * @param size The size of the array.
	 * @return true if the combination of 'a' and 'b' values is found in the array, false otherwise.
	 */
	bool searchArray(const Algebra ar[], int size) const
	{
		for (int i = 0; i < size; i++)
		{
			if ((a == ar[i].a) && (b == ar[i].b))
				return true;
		}

		return false;
	}


};

int main()
{
	//-----------------------------------------------//
	// Initializing array with default and specified values
	//Algebra a[] = { Algebra(), Algebra(1, 2), Algebra(3, 4), Algebra(a[1]), Algebra() };

	// Creating array of objects
	Algebra ar[5];

	// Setting data for array ar
	for (int i = 0; i < 5; i++)
		ar[i].setData(i, i + 1);

	// Printing data of array ar
	for (int i = 0; i < 5; i++)
		ar[i].print();
	//-----------------------------------------------//

	//-----------------------------------------------//
	// Creating and initializing an array of Algebra objects on the heap
	Algebra* po = new Algebra[3]{ Algebra(44, 55), Algebra(), Algebra(66, 77) };

	// Printing data of objects in the heap-allocated array
	for (int i = 0; i < 3; i++)
	{
		po[i].print(); // Or (po + i)->print();
	}

	delete[] po; // Free memory resources allocated on the heap
	//-----------------------------------------------//

	return 0;
}