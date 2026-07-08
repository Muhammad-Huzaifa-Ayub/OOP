#include "iostream"

using namespace std;

// Class A definition
class A
{
	int dA;  // Private member variable to store data for class A

public:
	// Default constructor
	A() : dA{ 0 }
	{
		cout << "A's Default Constructor." << endl;
	}

	// Parameterized constructor
	A(int _dA) : dA{ _dA }
	{
		cout << "A's Parameterized Constructor." << endl;
	}

	// Copy constructor
	A(const A& obj) : dA{ obj.dA }
	{
		cout << "A's Copy Constructor." << endl;
	}

	// Virtual destructor
	virtual ~A()
	{
		cout << "A's Destructor." << endl;
	}

	// Virtual print function to be overridden in derived classes
	virtual void print() const
	{
		cout << "dA = " << dA << endl;
	}

	// Virtual test function to be overridden in derived classes
	virtual void test() const
	{
		cout << "Class A's Test" << endl;
	}
};

// Class B definition, inheriting from class A
class B : public A
{
	int dB;  // Private member variable to store data for class B

public:
	// Default constructor
	B() : dB{ 0 }
	{
		cout << "B's Default Constructor." << endl;
	}

	// Parameterized constructor, calling A's parameterized constructor
	B(int _dA, int _dB) : A{ _dA }, dB{ _dB }
	{
		cout << "B's Parameterized Constructor." << endl;
	}

	// Copy constructor, calling A's copy constructor
	B(const B& obj) : A{ obj }, dB{ obj.dB }
	{
		cout << "B's Copy Constructor." << endl;
	}

	// Destructor
	~B()
	{
		cout << "B's Destructor." << endl;
	}

	// Print function to display the values of dA and dB
	void print() const override // Indicates that this function overrides a virtual function in the base class
	{
		A::print();  // Call to A's print function to display dA
		cout << "dB = " << dB << endl;
	}

	// Overridden test function
	void test() const override // Indicates that this function overrides a virtual function in the base class
	{
		cout << "Class B's Test" << endl;
	}
};

// Class C definition, inheriting from class A
class C : public A
{
	int dC;  // Private member variable to store data for class C

public:
	// Default constructor
	C() : dC{ 0 }
	{
		cout << "C's Default Constructor." << endl;
	}

	// Parameterized constructor, calling A's parameterized constructor
	C(int _dA, int _dC) : A{ _dA }, dC{ _dC }
	{
		cout << "C's Parameterized Constructor." << endl;
	}

	// Copy constructor, calling A's copy constructor
	C(const C& obj) : A{ obj }, dC{ obj.dC }
	{
		cout << "C's Copy Constructor." << endl;
	}

	// Destructor
	~C()
	{
		cout << "C's Destructor." << endl;
	}

	// Overridden print function
	void print() const override // Indicates that this function overrides a virtual function in the base class
	{
		A::print();  // Call to A's print function to display dA
		cout << "dC = " << dC << endl;
	}

	// Overridden test function
	void test() const override // Indicates that this function overrides a virtual function in the base class
	{
		cout << "Class C's Test" << endl;
	}
};

int main()
{
	// Creating objects of classes A, B, and C using parameterized constructors
	A oa(1);
	B ob(2, 3);
	C oc(4, 5);

	// Array of base class pointers holding references to objects of A, B, and C
	A* pa[3] = { &oa, &ob, &oc };

	// Loop to demonstrate polymorphism
	for (int i = 0; i < 3; i++)
	{
		pa[i]->test();  // Decision will be made at runtime based on the actual object type, not the pointer type
	}

	// Demonstrating dynamic memory allocation and polymorphism
	A* p = new B(1, 2);

	/*
	 Deleting the object pointed by p
	 Destructor of class B followed by class A will be executed
	 Because the base class (A)'s destructor was made virtual
	*/
	delete p;

	return 0;
}