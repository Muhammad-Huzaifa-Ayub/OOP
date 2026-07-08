#include <iostream>

using namespace std;

// Allocates an integer on 'heap' and returns its address
int* getVariableAddressOnHeap()
{
    int* p = new int;

    cout << "Number? ";
    cin >> *p;

    return p;
}

int main() 
{
    // ptr holds the address of the memory location returned by getVariableAddressOnHeap function
    int* ptr = getVariableAddressOnHeap();

    cout << "The Number is: " << *ptr;

    // Freeing memory allocated on 'heap'
    delete ptr;

    return 0;
}