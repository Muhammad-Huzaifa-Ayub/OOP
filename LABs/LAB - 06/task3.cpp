#include<iostream>
#include<iomanip>
#include<cstring>
#include<ctime>
#include<cstdlib>

using namespace std;

const int NAME_SIZE = 41;

class Student{
	
	private :
	
	int Roll_Number;
	char Name[NAME_SIZE];
	int noOfQuiz;
	int *Marks;
	int Total_Marks;
	
	void inputMarks ( )
	{
		for ( int i = 0; i < noOfQuiz; i++ )
		{
			//cout << "Enter Marks " << i+1 << " : ";
			Marks[i] = rand() % 10 + 1;
			//cin >> Marks[i];
			if ( Marks[i] <= 0 || Marks[i] > Total_Marks )
			{
				cout << "Please Enter Valid Marks ! " << endl;
				break;
			}
			
		}
	}
	
	public :
		
	Student()
	{
		Roll_Number = 0;
		Name[0] = '\0';
		noOfQuiz = 0;
		Marks = nullptr;
		Total_Marks = 10;	
	}
	Student ( int roll, const char* name, int nq, int tm )
	{
		Roll_Number = roll;
		strcpy(Name,name);
		noOfQuiz = nq;
		Marks = new int[noOfQuiz];
		for ( int i = 0; i < noOfQuiz; i++ )
		{
			Marks[i] = 0;
		}
		Total_Marks = tm;	
	}
	~Student()
	{
		delete[] Marks;
		Marks = nullptr;
	}
	Student ( const Student &ref )
	{
		Roll_Number = ref.Roll_Number;
		strcpy(Name,ref.Name);
		noOfQuiz = ref.noOfQuiz;
		Marks = new int[noOfQuiz];
		for ( int i = 0; i < noOfQuiz; i++ )
		{
			Marks[i] = ref.Marks[i];
		}
		Total_Marks = ref.Total_Marks;
		
	}
	void getInputFromUser( )
	{
		int roll = 0;
		char name[NAME_SIZE];
		int nq = 0;
		int tm = 0;
		
		cout << endl << endl;
		cout << "Enter student Roll no. : ";
		cin >> roll;
		cout << "Enter student Name     : ";
		cin >> name;
		cout << "Enter student No. of Quiz : ";
		cin >> nq;
		cout << "Enter total marks of Quiz : ";
		cin >> tm;
		cout << endl << endl;
			
		Roll_Number = roll;
		strcpy(Name,name);
		noOfQuiz = nq;
		if  ( Marks != nullptr )
		{
			delete[] Marks;
		}
		Marks = new int[noOfQuiz];
		Total_Marks = tm;
		
		inputMarks();
	}
	void display()
	{
		cout << setw(12) << left << "Roll No."<< setw(17) << left << "Student Name" << setw(17) << left << "No. of Quiz ";
		for ( int i = 0; i < noOfQuiz; i++ )
		{
			string str =  "Marks" + to_string( i+1 );
			cout << setw(8) << left << str;
		}
		cout << "\t"; cout << setw(15) << left << "Average Marks" << endl;
		
		int sum = 0;	
		cout << setw(12) << left << Roll_Number << setw(17) << left << Name << setw(17) << left << noOfQuiz;
		for ( int i = 0; i < noOfQuiz; i++ )
		{
			cout << setw(8) << left << Marks[i];
			sum += Marks[i];
		}
		cout << "\t"; cout << setw(15) << left << sum / (float)noOfQuiz << endl;
	}
};

void printStudent( Student s )
{
	s.display();
	
}

int main()
{
	srand(time(0));
	Student s1;
	s1.getInputFromUser();
	s1.display();
	
	cout << endl << endl << endl;
	
	Student s2 ( s1 );
	printStudent( s2 );
	
	return 0;
}