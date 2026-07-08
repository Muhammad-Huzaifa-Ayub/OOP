#include <iostream>

using namespace std;

int main() 
{

    //creating an integer on 'heap' memory
    int* pi = new int(5);

    cout << "Address of pi\t\t: " << &pi << endl;
    cout << "Value in pi\t\t: " << pi << endl;  
    cout << "Dereferencing pi\t: " << *pi << endl;

    //freeing memory allocated on 'heap'
    delete pi;

    return 0;
}