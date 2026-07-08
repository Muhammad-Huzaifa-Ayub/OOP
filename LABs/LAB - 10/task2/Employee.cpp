#include "Employee.h"

Employee::Employee()
{
    Name[0] = '\0';
    No = 0;
}
Employee::Employee(const char *Name, int No)
{
    strcpy(this->Name,Name);
    this->No = No;
}
void Employee::setName(const char *Name)
{
    strcpy(this->Name,Name);
}
const char * Employee::getName() const
{
    return this->Name;
}
void Employee::setNo(int &No)
{
    this->No = No;
}
int Employee::getNo() const
{
    return this->No;
}
void Employee::display()const
{
    cout << "Employee Name : " << Name << endl;
    cout << "Employee No.  : " << No << endl;
}