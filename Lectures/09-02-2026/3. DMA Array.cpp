#include <iostream>

using namespace std;

int main() 
{
    int ar_size = 5;

    // Creating an array on 'heap' memory
    int* pi = new int[ar_size];

    // Initializing array contents
    for (int i = 0; i < ar_size; i++)
    {
        pi[i] = i + 1;

        // OR

        // *(pi + i) = i + 1;
    }

    cout << "Array contents: ";
    for (int i = 0; i < ar_size; i++)
    {
        cout << pi[i] << "\t";
    }
    
    // Freeing memory allocated on 'heap'
    delete[] pi;

    return 0;
}
