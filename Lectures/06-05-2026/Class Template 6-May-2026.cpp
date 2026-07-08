#include "iostream"

using namespace std;

// Class template for algebraic operations
template<typename T>
class Algebra
{
    T a, b;		// Data members

public:
    // Default constructor
    Algebra()
    {
        a = b = 0;
    }

    // Parameterized constructor
    Algebra(T a, T b)
    {
        this->a = a;
        this->b = b;
    }

    // Member function to get input from user for data members
    void getData()
    {
        cout << "Enter a = ";
        cin >> a;

        cout << "Enter b = ";
        cin >> b;
    }

    // Member function to display data members on the screen
    void print();

    // Overloaded stream extraction operator as a friend function
    friend istream& operator>> (istream& in, Algebra& obj)
    {
        cout << "Enter a = ";
        in >> obj.a;

        cout << "Enter b = ";
        in >> obj.b;

        return in;
    }

    // Declaration of overloaded stream insertion operator as a friend function
    template<typename t>
    friend ostream& operator<< (ostream& out, const Algebra<t>& obj);
};

// Definition of member function to print data members
template<typename T>
void Algebra<T>::print()
{
    cout << "a = " << a << "\t" << "b = " << b << endl;
}

// Definition of overloaded stream insertion operator as a friend function
template<typename t>
ostream& operator<< (ostream& out, const Algebra<t>& obj)
{
    out << "a = " << obj.a << "\t" << "b = " << obj.b << endl;
    return out;
}

int main()
{
    // Template class for integers
    Algebra<int> obji;
    obji.getData();
    obji.print();

    // Template class for floats
    Algebra<float> objf(1.1f, 2.2f);
    objf.print();

    // Template class for characters
    Algebra<char> objc;
    cin >> objc;
    cout << objc;

    return 0;
}