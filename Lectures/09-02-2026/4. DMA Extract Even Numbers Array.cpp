#include <iostream>

using namespace std;

void print(int* p, int size)
{
    cout << "Array contents: ";

    for (int i = 0; i < size; i++)
    {
        cout << *(p + i) << "\t";   
        // OR
        // cout << p[i] << "\t";
    }

    cout << endl;
}

// Returns a reference to an array allocated on 'heap' that contains all even numbers
// in 'ar'. 'even_size' holds the count of even numbers.
int* getEvenNumbers(const int ar[], const int ar_size, int& even_size)
{
    even_size = 0;

    // Count of even numbers in 'ar'
    for (int i = 0; i < ar_size; i++)
    {
        if (ar[i] % 2 == 0)
            even_size++;
    }

    // Allocates a new array on the heap to store even numbers
    int* evenArray = new int[even_size];
    
    // Storing even numbers in the array
    for (int i = 0, j = 0; i < ar_size; i++)
    {
        if (ar[i] % 2 == 0)
        {
            evenArray[j++] = ar[i];
        }
    }

    // Returns a reference to the even number array
    return evenArray;
}

int main() 
{
    int evenCount = 0;
    
    const int ar_size = 10;
    int ar[ar_size] = {3, 2, 7, 9, 1, 4, 6, 12, 0, 98};    

    // Storing the returned reference in 'ptrEven'
    int* ptrEven = getEvenNumbers(ar, ar_size, evenCount);

    // Printing the even numbers
    print(ptrEven, evenCount);
    
    // Freeing memory allocated on 'heap'
    delete[] ptrEven;

    return 0;
}