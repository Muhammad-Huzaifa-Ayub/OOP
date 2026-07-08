#include <iostream>
using namespace std;

// Base Class
class Person
{
protected:
    string name;

public:
    Person(string n)
    {
        name = n;
        cout << "Person Constructor" << endl;
    }

    ~Person()
    {
        cout << "Person Destructor" << endl;
    }
};

// Derived Class 1
class Student : public Person
{
protected:
    int rollNo;

public:
    Student(string n, int r)
        : Person(n)
    {
        rollNo = r;
        cout << "Student Constructor" << endl;
    }

    ~Student()
    {
        cout << "Student Destructor" << endl;
    }
};

// Derived Class 2
class Employee : public Person
{
protected:
    int empID;

public:
    Employee(string n, int id)
        : Person(n)
    {
        empID = id;
        cout << "Employee Constructor" << endl;
    }

    ~Employee()
    {
        cout << "Employee Destructor" << endl;
    }
};

// Derived from both Student & Employee
class Result : public Student, public Employee
{
private:
    float marks;

public:
    Result(string n, int r, int id, float m)
        : Student(n, r), Employee(n, id)
    {
        marks = m;
        cout << "Result Constructor" << endl;
    }

    ~Result()
    {
        cout << "Result Destructor" << endl;
    }

    void display()
    {
        cout << "Name (Student side): "
             << Student::name << endl;

        cout << "Roll No: "
             << rollNo << endl;

        cout << "Employee ID: "
             << empID << endl;

        cout << "Marks: "
             << marks << endl;
    }
};

int main()
{
    Result r1("Ali", 101, 5001, 88.5);

    cout << endl;
    r1.display();

    return 0;
}