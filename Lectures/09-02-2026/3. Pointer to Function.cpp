#include <iostream>

using namespace std;

void printValueByPointer(int* ptr)
{
    cout << "*ptr = " << *ptr << endl;
}

void changeValueByPointer(int* ptr)
{
    cout << "Value? ";
    cin >> *ptr;    
}

int main() 
{
    int a(5), b(6);

    //passing address of variable 'a' to 'printValueByPointer' function
    printValueByPointer(&a);

    //passing address of variable 'b' to 'printValueByPointer' function
    printValueByPointer(&b);

    //passing address of variable 'a' to 'changeValueByPointer' function
    changeValueByPointer(&a);

    //passing address of variable 'a' to 'printValueByPointer' function
    printValueByPointer(&a);

    return 0;
}