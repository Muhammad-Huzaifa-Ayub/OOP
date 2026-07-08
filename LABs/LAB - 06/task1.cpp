#include<iostream>
#include<cstring>

using namespace std;

const int NAME_SIZE = 50; 
const int DEPT_SIZE = 50;

class Employee{
	
	private : 
	
	int ID;
	char Name[NAME_SIZE];
	char Dep_Name[DEPT_SIZE];
	
	public :
	
	Employee()
	{
		ID = 0;
		Name[0] = '\0';
		Dep_Name[0] = '\0';
	}
	Employee( int id, const char* name, const char* dept_name )
	{
		ID = id;
		strcpy(Name,name);
		strcpy(Dep_Name,dept_name);
	}
	Employee( int id, const char* name)
	{
		ID = id;
		strcpy(Name,name);
		Dep_Name[0] = '\0';
	}
	void setID( int id ) 
	{
		ID = id;
	}
	void setName(const char* name ) 
	{
		strcpy(Name,name);
	
	}
	void setDeptName(const char* dept_name ) 
	{
		strcpy(Dep_Name,dept_name);
	}
	int getID(  ) const
	{
		return ID;
	}
	const char* getName( ) const
	{
		return Name;
	
	}
	const char* getDepName( ) const
	{
		return Dep_Name;
	}
	void DisplayEmployee( )	const
	{
		cout << endl;
		cout << "Employee ID   : " << getID() << endl;
		cout << "Employee Name : " << getName() << endl;
		cout << "Employee Dept. Name : " <<  getDepName() << endl;
		cout << endl;
	}
};

int main()
{
	Employee e1;
	
	Employee e2(1010,"M.Ali","English");
	
	e1.DisplayEmployee();
	e2.DisplayEmployee();
	
	int n = 0;
	cout << "Enter no. of Employee's : ";
	cin >> n; cout << endl << endl;
	Employee *emp = new Employee[n];

	for ( int i = 0; i < n; i++ )
	{
		int ID;
		char Name[NAME_SIZE];
		char Dept_Name[DEPT_SIZE];
		cout << "Enter Employee (" << i+1 << ") ID   : ";
		cin >> ID;
		cout << "Enter Employee (" << i+1 <<  ") Name : ";
		cin >> Name;
		cout << "Enter Employee (" << i+1 << ") Dept. Name : ";
		cin >> Dept_Name;
		cout << endl << endl;

		emp[i].setID( ID );
		emp[i].setName( Name );
		emp[i].setDeptName(Dept_Name );	 
	}

	cout << "\t\t\tDisplay All ";
	for ( int i = 0; i < n; i++ )
	{
		emp[i].DisplayEmployee();
	}

	return 0;
}