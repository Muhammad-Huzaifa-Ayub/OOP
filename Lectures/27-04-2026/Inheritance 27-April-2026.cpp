#include <iostream>
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

    // Destructor
    ~A()
    {
        cout << "A's Destructor." << endl;
    }

    // Print function to display the value of dA
    void print() const
    {
        cout << "dA = " << dA << endl;
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
    void print() const
    {
        A::print();  // Call to A's print function to display dA
        cout << "dB = " << dB << endl;
    }
};

int main()
{
    // Creating an object of class A with parameterized constructor
    A oa(51);

    // Creating an object of class B with parameterized constructor
    B ob(1, 2);

    // Calling A's print function using an object of class B
    ob.A::print();
    cout << endl;
    
    // Calling B's print function
    ob.print();
    cout << endl;

    // Assigning an object of class B to an object of class A
    // This is possible because B is a derived class of A
    oa = ob;
    
    /* 
     Calling A's print function
     A(parent) class's print member function will be called because the call is made based on the object type, 
     which is A. Object slicing occurs here; only the A part of ob is assigned to oa.
    */
    oa.print();
    

    return 0;
}