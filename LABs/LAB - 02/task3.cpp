#include<iostream>
#include<string>
#include<cstring>

using namespace std;

struct Employee{
		
		char fName[20];
		char LName[20];
		int bYear;
		char bMonth[4];
		int bDay;
		int jYear;
		char jMonth[4];
		int jDay;
		long salary;
	};
	
Employee e1;

void initEmployee()
{
	strcpy ( e1.fName, "Muhammad Huzaifa");
	strcpy ( e1.LName, "Ayub");
	e1.bYear = 2007;
	strcpy ( e1.bMonth, "Apr");
	e1.bDay = 30;
	e1.jYear = 2025;
	strcpy ( e1.jMonth, "Sep");
	e1.jDay = 8;
	e1.salary = 100000;
	
}

void viewEmployee()
{
	cout << "Employee first Name : " << e1.fName << endl;
	cout << "Last Name : " << e1.LName << endl;
	cout << "Birthday Year : " << e1.bYear << endl;
	cout << "Birthday Month : " << e1.bMonth << endl;
	cout << "Birthday Date : " << e1.bDay << endl;
	cout << "Joining Year : " << e1.jYear << endl;
	cout << "Joining Month : " << e1.jMonth << endl;
	cout << "Joining Date : " << e1.jDay << endl;
	cout << "Salary : " << e1.salary << endl;
	
}

void addEmployee()
{
	cout << "Enter Employee first Name : ";
	cin >> e1.fName;
	cout << "Enter Last Name : ";
	cin >> e1.LName;
	cout << "Enter Birthday Year : ";
	cin >> e1.bYear;
	cout << "Enter Birthday Month : ";
	cin >> e1.bMonth;
	cout << "Enter Birthday Date : ";
	cin >> e1.bDay;
	cout << "Enter Joining Year : ";
	cin >> e1.jYear;
	cout << "Enter Joining Month : ";
	cin >> e1.jMonth;
	cout << "Enter Joining Date : ";
	cin >> e1.jDay;
	cout << "Enter Salary : ";
	cin >> e1.salary;
	
}

int main()
{
	
	initEmployee();
	viewEmployee();
	cout << endl << endl << endl;
	addEmployee();
	cout << endl << endl << endl;
	viewEmployee();
	
	return 0;
}