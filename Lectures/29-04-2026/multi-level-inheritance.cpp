#include <iostream>
using namespace std;

// Base Class
class Person
{
protected:
    string name;
    int age;

public:
    // Default Constructor
    Person()
    {
        cout << "Person Default Constructor" << endl;
    }

    // Parameterized Constructor
    Person(string n, int a)
    {
        name = n;
        age = a;
        cout << "Person Parameterized Constructor" << endl;
    }

    // Destructor
    ~Person()
    {
        cout << "Person Destructor" << endl;
    }

    void displayPerson()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};


// Derived Class (Level 1)
class Student : public Person
{
protected:
    int rollNo;

public:
    // Default Constructor
    Student()
    {
        cout << "Student Default Constructor" << endl;
    }

    // Parameterized Constructor
    Student(string n, int a, int r)
        : Person(n, a)   // Calling Person constructor
    {
        rollNo = r;
        cout << "Student Parameterized Constructor" << endl;
    }

    // Destructor
    ~Student()
    {
        cout << "Student Destructor" << endl;
    }

    void displayStudent()
    {
        displayPerson();
        cout << "Roll No: " << rollNo << endl;
    }
};


// Derived Class (Level 2)
class Result : public Student
{
private:
    float marks;

public:
    // Parameterized Constructor
    Result(string n, int a, int r, float m)
        : Student(n, a, r)   // Calling Student constructor
    {
        marks = m;
        cout << "Result Constructor" << endl;
    }

    // Destructor
    ~Result()
    {
        cout << "Result Destructor" << endl;
    }

    void displayResult()
    {
        cout << endl;
        cout << "Displaying Result:" << endl;

        displayStudent();
        cout << "Marks: " << marks << endl;
    }
};


// Main Function
int main()
{
    cout << "Creating Object r1" << endl;

    Result r1("Ali", 20, 101, 89.5);

    r1.displayResult();

    cout << endl;
    cout << "End of main()" << endl;

    return 0;
}