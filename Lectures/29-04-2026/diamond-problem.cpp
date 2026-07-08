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
};

class Student : public Person
{
};

class Employee : public Person
{
};

class Result : public Student, public Employee
{
};

int main()
{
    Result r1;

    // Ambiguity occurs:
    r1.name = "Ali";  // ERROR

    //r1.Student::name = "Ali"; // OK

    cout << r1.Student::name;

    return 0;
}