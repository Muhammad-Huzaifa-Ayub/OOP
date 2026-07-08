#include <iostream>
using namespace std;

class Person
{
public:
    string name;

    Person()
    {
        cout << "Person Constructor" << endl;
    }

    ~Person()
    {
        cout << "Person Destructor" << endl;
    }
};

// Virtual Inheritance
class Student : virtual public Person
{
public:
    Student()
    {
        cout << "Student Constructor" << endl;
    }

    ~Student()
    {
        cout << "Student Destructor" << endl;
    }
};

class Employee : virtual public Person
{
public:
    Employee()
    {
        cout << "Employee Constructor" << endl;
    }

    ~Employee()
    {
        cout << "Employee Destructor" << endl;
    }
};

class Result : public Student, public Employee
{
public:
    Result()
    {
        cout << "Result Constructor" << endl;
    }

    ~Result()
    {
        cout << "Result Destructor" << endl;
    }
};

int main()
{
    Result r1;

    r1.name = "Ali"; // No ambiguity now

    cout << "\nName: " << r1.name << endl;
    //cout << "\nsizeof: " << sizeof(r1.name) << endl;

    return 0;
}