#include<iostream>
#include<string>
#include<cstring>

using namespace std;

const int noOfEmployee = 5;

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

Employee e1[noOfEmployee];
	


void viewEmployee(int i)
{
	cout << "Employee first Name : " << e1[i].fName << endl;
	cout << "Last Name : " << e1[i].LName << endl;
	cout << "Birthday Year : " << e1[i].DOB.bYear << endl;
	cout << "Birthday Month : " << e1[i].DOB.bMonth << endl;
	cout << "Birthday Date : " << e1[i].DOB.bDay << endl;
	cout << "Joining Year : " << e1[i].joining.jYear << endl;
	cout << "Joining Month : " << e1[i].joining.jMonth << endl;
	cout << "Joining Date : " << e1[i].joining.jDay << endl;
	cout << "Salary : " << e1[i].salary << endl;
	
}

void addEmployee(int i)
{
	cout << "Enter Employee first Name : ";
	cin >> e1[i].fName;
	cout << "Enter Last Name : ";
	cin >> e1[i].LName;
	cout << "Enter Birthday Year : ";
	cin >> e1[i].DOB.bYear;
	cout << "Enter Birthday Month : ";
	cin >> e1[i].DOB.bMonth;
	cout << "Enter Birthday Date : ";
	cin >> e1[i].DOB.bDay;
	cout << "Enter Joining Year : ";
	cin >> e1[i].joining.jYear;
	cout << "Enter Joining Month : ";
	cin >> e1[i].joining.jMonth;
	cout << "Enter Joining Date : ";
	cin >> e1[i].joining.jDay;
	cout << "Enter Salary : ";
	cin >> e1[i].salary;
	
}

void searchEmployee(int s,char name[])
{
	for ( int i = 0; i < noOfEmployee; i++ )
	{
		bool flag = true;
		for ( int j = 0; j < s; j++ )
		{
			if ( e1[i].LName[j] != name[j])
			{
				flag = false;
			}
		}
		if ( flag )
		{
			viewEmployee(i);
		}
	}
	
}

int main()
{
	
	char name[20];
	short int s = 0;
	for ( int i = 0; i < noOfEmployee; i++ )
	{
		cout << "========== Employee - " << i+1 << " ==========" << endl;
		addEmployee(i);
	}
	cout << endl << endl << endl;
	cout << "Enter last name to get record of employee : ";
	cin >> name;
	cout << endl << endl;
	s = strlen(name);
	
	searchEmployee(s,name);
			
	return 0;
}