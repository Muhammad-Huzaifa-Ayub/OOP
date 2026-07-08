#include<iostream>
#include<string>
#include<cstring>

using namespace std;

struct DateOfBirth{
	
		int bYear;
		char bMonth[4];
		int bDay;
};

struct JoiningDate{
	
		int jYear;
		char jMonth[4];
		int jDay;
};

struct Employee{
		
		char fName[20];
		char LName[20];
		JoiningDate joining;
		DateOfBirth DOB;
		
		long salary;
	};
	
Employee e1;

void initEmployee()
{
	strcpy ( e1.fName, "Muhammad Huzaifa");
	strcpy ( e1.LName, "Ayub");
	e1.DOB.bYear = 2007;
	strcpy ( e1.DOB.bMonth, "Apr");
	e1.DOB.bDay = 30;
	e1.joining.jYear = 2025;
	strcpy ( e1.joining.jMonth, "Sep");
	e1.joining.jDay = 8;
	e1.salary = 100000;
	
}

void viewEmployee()
{
	cout << "Employee first Name : " << e1.fName << endl;
	cout << "Last Name : " << e1.LName << endl;
	cout << "Birthday Year : " << e1.DOB.bYear << endl;
	cout << "Birthday Month : " << e1.DOB.bMonth << endl;
	cout << "Birthday Date : " << e1.DOB.bDay << endl;
	cout << "Joining Year : " << e1.joining.jYear << endl;
	cout << "Joining Month : " << e1.joining.jMonth << endl;
	cout << "Joining Date : " << e1.joining.jDay << endl;
	cout << "Salary : " << e1.salary << endl;
	
}

void addEmployee()
{
	cout << "Enter Employee first Name : ";
	cin >> e1.fName;
	cout << "Enter Last Name : ";
	cin >> e1.LName;
	cout << "Enter Birthday Year : ";
	cin >> e1.DOB.bYear;
	cout << "Enter Birthday Month : ";
	cin >> e1.DOB.bMonth;
	cout << "Enter Birthday Date : ";
	cin >> e1.DOB.bDay;
	cout << "Enter Joining Year : ";
	cin >> e1.joining.jYear;
	cout << "Enter Joining Month : ";
	cin >> e1.joining.jMonth;
	cout << "Enter Joining Date : ";
	cin >> e1.joining.jDay;
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