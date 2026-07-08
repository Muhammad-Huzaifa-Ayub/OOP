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

    void displayPerson()
    {
        cout << "Name: " << name << endl;
    }
};

// Derived Class 1
class Student : public Person
{
private:
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

    void displayStudent()
    {
        displayPerson();
        cout << "Roll No: " << rollNo << endl;
    }
};

// Derived Class 2
class Teacher : public Person
{
private:
    string subject;

public:
    Teacher(string n, string s)
        : Person(n)
    {
        subject = s;
        cout << "Teacher Constructor" << endl;
    }

    ~Teacher()
    {
        cout << "Teacher Destructor" << endl;
    }

    void displayTeacher()
    {
        displayPerson();
        cout << "Subject: " << subject << endl;
    }
};

int main()
{
    cout << "Creating Student Object\n";
    Student s1("Ali", 101);

    cout << "\nCreating Teacher Object\n";
    Teacher t1("Ahmed", "OOP");

    cout << "\nDisplaying Data\n";

    s1.displayStudent();
    cout << endl;
    t1.displayTeacher();

    return 0;
}