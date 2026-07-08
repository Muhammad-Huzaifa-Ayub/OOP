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

// Returns a reference to an array allocated on 'heap' that contains all elements of
// in 'ar1' and 'ar2'. 'size' holds the number of elements for new array.
int* mergeArrays(const int ar1[], const int ar2[], const int ar1_size, const int ar2_size, int& size)
{
    // Size of new array
    size = ar1_size + ar2_size;

    // Allocates a new array on the heap to store elements of 'ar1' and 'ar2' array
    int* p = new int[size];

    int j = 0;

    // Copying elements of 'ar1' array to new array pointed by 'p'
    for (int i = 0; i < ar1_size; i++)
    {
        p[j++] = ar1[i];
    }

    // Copying elements of 'ar2' array to new array pointed by 'p'
    for (int i = 0; i < ar2_size; i++)
    {
        p[j++] = ar2[i];
    }

    // Returns reference of new array that holds 'ar1' and 'ar2' array elements  
    return p;
}

int main() 
{
    const int ar1_size = 10;
    int ar1[ar1_size] = {3, 2, 7, 9, 1, 4, 6, 12, 0, 98};

    const int ar2_size = 5;
    int ar2[ar2_size] = {100, 101, 102, 103, 104};    

    int mergedArray_size = 0;

    // Storing the returned reference in 'ptrMergedArray'
    int* ptrMergedArray = mergeArrays(ar1, ar2, ar1_size, ar2_size, mergedArray_size);
    
    // Printing the ptrMergedArray contents
    print(ptrMergedArray, mergedArray_size);
    
    // Freeing memory allocated on 'heap'
    delete[] ptrMergedArray;

    return 0;
}