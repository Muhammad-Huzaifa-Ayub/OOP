#include "iostream"
#include "string"  

using namespace std;

// Define the CPU class
class CPU
{
    // Private member variables to store the model and name of the CPU
    int model;
    string name;

public:
    // Default constructor
    CPU() : model{ -1 }, name{ -1 }
    {
        cout << "CPU Default Constructor" << endl;
    }

    // Parameterized constructor
    CPU(int model, string name) : model{ model }, name{ name }
    {
        cout << "CPU Parameterized Constructor" << endl;
    }

    // Copy constructor
    CPU(const CPU& obj) : model{ obj.model }, name{ obj.name }
    {
        cout << "CPU Copy Constructor" << endl;
    }
    

    // Destructor
    ~CPU()
    {
        cout << "CPU Destructor." << endl; 
    }

    // Member function to print the CPU's information
    void printInfo()
    {
        cout << "CPU Model = " << model << "\tCPU Name = " << name << endl;
    }
};

// Define the Computer class
class Computer
{
    // Private member variables to store the make year and name of the computer
    int makeYear;
    string name;

    // Composition relationship: Computer "has-a" CPU
    CPU m_cpu; // CPU object is composed within Computer. The life cycle of m_cpu depends on the Computer object.

public:
    // Default constructor
    Computer() : makeYear{ -1 }, name{ "" }
    {
        cout << "Computer Default Constructor" << endl;
    }

    // Parameterized constructor
    // Initializes Computer with makeYear, name, and initializes CPU with cpuCode and cpuName
    Computer(int computerMakeYear, string computerName, int cpuCode, string cpuName) :
        makeYear{ computerMakeYear }, name{ computerName }, m_cpu{ cpuCode, cpuName }
    {
        cout << "Computer Parameterized Constructor" << endl;
    }

    // Copy constructor
    // Initializes Computer with another Computer object and initializes CPU with the CPU of the given Computer object
    Computer(const Computer& obj) : 
        makeYear{ obj.makeYear }, name{ obj.name }, m_cpu{ obj.m_cpu }
    {
        cout << "Computer Copy Constructor" << endl;
    }

    // Destructor
    ~Computer()
    {
        cout << "Computer Destructor." << endl; // Print a message when the Computer object is destroyed
    }

    // Member function to print the Computer's information
    void printInfo()
    {
        cout << "Computer Make Year = " << makeYear << "\t Computer Name = " << name << endl; // Print make year and name

        m_cpu.printInfo(); // Call CPU's printInfo to display its data
    }
};

// Main function
int main()
{
    // Create a Computer object using the parameterized constructor
    Computer c_obj{ 2024, "DELL", 1009, "Intel" };

    // Print the information of the Computer object
    c_obj.printInfo();

    return 0; 
}