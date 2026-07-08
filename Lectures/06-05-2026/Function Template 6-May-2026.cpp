#include "iostream"

using namespace std;

// Function template to add two numbers of the same type
template<class T>
T add(T value1, T value2)
{
    return value1 + value2;
}

// Function template with two parameters of potentially different types
template<class T1, class T2>
T1 multiply(T1 a, T2 b)
{
    return a * b;
}

// Function template to display the content of an array
template<typename ArrayType>
void printArray(const ArrayType ar[], const int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << ar[i] << "\t";
    }

    cout << endl;
}

int main()
{
    // Example usage of the add function template with integers, floats, and chars
    cout << "Adding integers: " << add(1, 2) << endl;  				// Output: 3
    cout << "Adding floats: " << add<float>(1.1f, 2.2f) << endl;	// Output: 3.3
    cout << "Adding chars: " << add<char>('a', 'b') << endl;		// Output: 195 ('a' + 'b' ASCII values)

    // Example of type mismatch error (commented out to prevent compilation errors)
    // cout << add(1, 1.2f) << endl; // Error: cannot deduce T from mixed types

    // Example usage of the multiply function template with floats and integers
    cout << "Multiplying float and int: " << multiply(3.2f, 2) << endl;	// Output: 6.4
    cout << "Multiplying float and int (explicit template arguments): " << multiply<float, int>(3.2f, 4) << endl;	// Output: 12.8

    // Example of printing integer array
    int i_array[] = { 1, 2, 3, 4, 5 };
    cout << "Integer array:" << endl;
    printArray(i_array, sizeof(i_array) / sizeof(int));			// Output: 1 2 3 4 5

    // Example of printing float array
    float f_array[] = { 1.1f, 2.2f, 3.3f };
    cout << "Float array:" << endl;
    printArray(f_array, sizeof(f_array) / sizeof(float));		// Output: 1.1 2.2 3.3

    // Example of printing character array
    char c_array[] = { 'A', 'B', 'C', 'D' };
    cout << "Character array:" << endl;
    printArray<char>(c_array, sizeof(c_array) / sizeof(char));	// Output: A B C D

    return 0;
}
