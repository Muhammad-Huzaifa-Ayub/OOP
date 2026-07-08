#include <iostream>

using namespace std;

void printArrayByPointer(int* ptr_array, int array_size)
{
    for (int i = 0; i < array_size; i++)
    {
        cout << ptr_array[i] << "\t";
        
        //OR 
        
        //cout << *(ptr_array + i) << "\t";
    }    
}

void inputArrayByPointer(int* ptr_array, int array_size)
{
    for (int i = 0; i < array_size; i++)
    {
        cout << "Enter " << i + 1 << " value: ";
        cin >> ptr_array[i];
        
        //OR 
        
        //cout << "Enter " << i + 1 << " value: ";
        //cin >> *(ptr_array + i);
    }    
}

int main() 
{
    const int size = 5;

    int ar[size]{ 1, 2, 3, 4, 5};
    
    //passing array 'ar' to 'inputArrayByPointer' function along with its 'size'
    inputArrayByPointer(ar, size);

    //passing array 'ar' to 'printArrayByPointer' function along with its 'size'
    printArrayByPointer(ar, size);

    return 0;
}