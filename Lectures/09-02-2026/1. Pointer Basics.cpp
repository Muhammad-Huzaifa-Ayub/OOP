#include "iostream"
#include "string"

using namespace std;

#include <iostream>

using namespace std;

int main() 
{
    int a = 5;

    // declare pointer 'pi' and assign the address of variable 'a' to it
    int* pi = &a;

    cout << "Address of pi\t\t: " << &pi << endl;
    cout << "Address of a\t\t: " << &a << endl;
    cout << "Value in pi\t\t: " << pi << endl;  
    cout << "Dereferencing pi\t: " << *pi << endl;

    return 0;
}
