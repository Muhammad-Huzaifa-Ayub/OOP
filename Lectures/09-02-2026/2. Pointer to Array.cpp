#include <iostream>

using namespace std;

int main() 
{
    const int size = 5;
    int ar[size] {1, 2, 3, 4, 5};

    // assigning array 'ar' address to pointer 'pa'
    int* pa = ar;

    cout << "Displaying the address and value of array 'ar' elements through pointer 'pa':" << endl;
    for (int i = 0; i < size; i++) 
    {
        cout << &pa[i] << "\t" << pa[i] << endl;
    }

    cout << endl << "Another way to traverse the array through pointer 'pa':" << endl;
    for (int i = 0; i < size; i++) 
    {
        cout << (pa + i) << "\t" << *(pa + i) << endl;
    }

    return 0;
}