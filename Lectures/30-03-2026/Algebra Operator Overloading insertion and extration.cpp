#include "iostream"

using namespace std;

class Algebra
{
	// Data members of the class
	int a, b;

public:

	// Default Constructor
	Algebra() : a{ 0 }, b{ 0 }
	{	}

	// Parameterized Constructor
	Algebra(int a, int b) : a{a}, b{b} 
	{	}

	// Copy Constructor
	Algebra(const Algebra& obj) : a(obj.a), b(obj.b)
	{	}

	// Destructor
	~Algebra()
	{	}

	// Setter for data member a
	void setA(int a)
	{
		this->a = a;
	}

	// Getter for data member a
	int getA() const
	{
		return a;
	}

	// Setter for data member b
	void setB(int b)
	{
		this->b = b;
	}

	// Getter for data member b
	int getB() const
	{
		return b;
	}

	// Function to set object's data
	void setData(int a, int b)
	{
		this->a = a;
		this->b = b;
	}

	// Function to take input for object's data
	void input()
	{
		cout << "Enter a = ";
		cin >> a;

		cout << "Enter b = ";
		cin >> b;
	}

	// Function to display object's data on screen
	void print() const
	{
		//this->a = 5;	Error, current object's reference is constant

		cout << "a = " << this->a << "\tb = " << (*this).b << endl;
	}

	/**
	 * @brief Overloaded binary addition operator for Algebra objects.
	 *
	 * This operator adds the corresponding 'a' and 'b' values of two Algebra objects and returns a new Algebra object with the result.
	 *
	 * @param obj The Algebra object to be added.
	 * @return A new Algebra object containing the sum of 'a' and 'b' values.
	 */
	Algebra operator+(const Algebra & obj) const
	{
		return Algebra(a + obj.a, b + obj.b);
	}

	/**
	 * @brief Overloaded equality operator for Algebra objects.
	 *
	 * This operator checks if the 'a' and 'b' values of two Algebra objects are equal.
	 *
	 * @param obj The Algebra object to compare with.
	 * @return true if the 'a' and 'b' values of both objects are equal, false otherwise.
	 */
	bool operator==(const Algebra& obj) const
	{
		return ((a == obj.a) && (b == obj.b));
	}

	// Overloaded assignment operator
	Algebra operator= (const Algebra& obj)
	{
		if (this != &obj)		// Avoiding self-assignment
		{
			// Copying member variables
			this->a = obj.a;
			this->b = obj.b;
		}	

		return *this;
	}

	// Overloaded binary += operator
	Algebra operator+= (const Algebra& obj)
	{

		// Add the corresponding members of obj to this object's members
		this->a += obj.a;
		this->b += obj.b;

		return *this;
	}

	// Overloaded - operator (unary)
	Algebra operator- () const
	{
		// Return a new Algebra object with negated values
		return Algebra(-a, -b);
	}

	// Overloaded pre-increment ++ operator (unary)
	Algebra operator++ ()
	{
		// Increment a and b
		++a;
		++b;

		// Return a reference to the modified object
		return *this;
	}

	// Overloaded post-increment ++ operator (unary)
	Algebra operator++ (int)
	{
		// Create a copy of the current state
		Algebra oldState(*this);

		// Increment a and b
		++a;
		++b;

		// Return the copy of the previous state
		return oldState;
	}

	// Overloaded stream-insertion << operator
	friend ostream& operator<< (ostream&, const Algebra&);

	// Overloaded stream-extraction << operator
	friend istream& operator>> (istream& in, Algebra& obj);
//	{
//		cout << "Enter a = ";
//		in >> obj.a;
//
//		cout << "Enter b = ";
//		in >> obj.b;
//
//		return in;
//	}
};

// Overloaded stream-insertion << operator
ostream& operator<< (ostream& out, const Algebra& obj)
{
	out << "a = " << obj.a << "\tb = " << obj.b << endl;

	return out;
}
istream& operator>> (istream& in, Algebra& obj)
	{
		cout << "Enter a = ";
		in >> obj.a;

		cout << "Enter b = ";
		in >> obj.b;

		return in;
	}

int main()
{
	Algebra obj1(1, 2), obj2(4, 5), obj3(7, 8);

	cin >> obj3;					// operator>> (cin, obj3);
	cout << obj3;					// operator<< (cout, obj3)

	return 0;
}