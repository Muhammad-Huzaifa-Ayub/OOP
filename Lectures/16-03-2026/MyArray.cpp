#include <iostream>

using namespace std;

class MyArray 
{
    int* p;         // Holds reference of array, created on heap
    int size;       // Holds the maximum size of array

public:
    // Default constructor
    MyArray() : size{ 5 } 
    {
        p = new int[size] {};   // Allocating array on heap and initializing to default data (zeroes)
    }

    // Overloaded constructor. Accepts the size of array as parameter
    MyArray(int size) : size{ size } 
    {
        p = new int[size] {};   // Allocating array on heap and initializing to default data (zeroes)
    }

    // Overloaded constructor. Accepts an array with its size and initializes object's data with them
   MyArray(const int ar[], int ar_size) : size{ ar_size } 
    {
        p = new int[size];      // Allocating array on heap
    
        for (int i = 0; i < size; i++) 
        {
            p[i] = ar[i];       // Initializing object's array with the data of array passed as argument
        }
    }

    // Copy constructor
    MyArray(const MyArray& obj) : size{ obj.size }
    {
        p = new int[size];      // Allocating array on heap

        for (int i = 0; i < size; i++) 
        {
            p[i] = obj.p[i];    // Initializing object's array with the data of right-hand side object
        }
    }

    // Destructor
    ~MyArray() 
    {
        delete[] p;    // Free memory resources allocated on heap
    }

    // Overloaded assignment operator
    MyArray& operator= (const MyArray& obj) 
    {
    	    	cout<<"Assignment operator"<<endl;

        // Check if the objects are not the same and have the same size
        if (this != &obj && this->size == obj.size) 
        {
            for (int i = 0; i < size; i++) 
            {
                p[i] = obj.p[i];    // Initializing object's array with the data of right-hand side object
            }
        }

        return *this;
    }

    // Member function to display array elements
    void print() const 
    {
        for (int i = 0; i < size; i++) 
        {
            cout << p[i] << "\t";
        }

        cout << endl;
    }

    // Overloaded index [] operator for constant objects to handle rvalue
    int operator[] (int index) const 
    {
    	  	cout<<"Index Operator"<<endl;

        if (index >= 0 && index < size) 
        {
            return p[index];    // Returning the value at the specified index
        }
        
       
    }

    // Overloaded index [] operator for non-constant objects to handle lvalue and rvalue
    int& operator[] (int index) 
    {
    	    	cout<<"Index Operator"<<endl;

        if (index >= 0 && index < size) 
        {
            return p[index];    // Returning a reference to the value at the specified index
        }
    }
    
    MyArray operator +(const MyArray & obj)
    {
    	cout<<"Operator +"<<endl;
    	if(this->size == obj.size)
    	{
    		MyArray newObj(this->size);
    		
    		for(int i=0;i<size;i++)
    		{
    			newObj.p[i]=this->p[i]+obj.p[i];
			}
			return newObj;
		}
	}
	bool operator == (const MyArray & obj)
	{
		if(this->size==obj.size)
			return true;
		else
			return false;
	}
    
};

int main() 
{
    int a[] = { 1, 2, 3, 4, 5, 6 };

    MyArray o1, o2;//, o3(a, 6), o4 (o3);


//	o1.insert(0,99);
//	o1.insert(1,98);
//	o1.insert(2,97);
//	o1.insert(3,96);
//	o1.insert(4,95);
    o1[0]=10;
    o1[1]=11;
    o1[2]=12;
    o1[3]=13;
	o1[4]=14;
	
	o2[0]=10;
    o2[1]=11;
    o2[2]=12;
    o2[3]=13;
	o2[4]=14;
	
	MyArray o9=o1+o2;
	
	o9.print();
    MyArray o3(10);
    if (o1==o3)
    { 
    	cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
		}    

    return 0;
}
