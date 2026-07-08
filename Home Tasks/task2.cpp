#include <iostream>

using namespace std;

class Set{

private:
	
	int *data;
	int capacity;
	int noOfElements;

public:
	
	Set( int cap = 5 );
	Set( const Set &ref );
	~Set();
	void insert ( int element); 
	void remove ( int element); 
	int getCardinality() const;
	Set calcUnion ( Set & s2 );
	Set calcIntersection ( Set & s2 );
	Set calcSymmetricDifference ( Set & s2 );
	Set calcDifference ( Set & s2 );
	bool isFound( const int element ) const;
	int isMember ( const int &val );
	int isSubSet ( const Set & s2 );
	void reSize ( int newcapacity );
	void DisplayData();
		
};

Set::Set( int cap )
	{
		if ( cap <= 0 )
		{
			capacity = 5;
		}
		else
		{
			capacity = cap;
		}

		data = new int[capacity];
		noOfElements = 0;
	}
	Set::~Set()
	{
		delete[] data;
		data = nullptr;
	}
	Set::Set( const Set &ref )
	{
		capacity = ref.capacity;
		noOfElements = ref.noOfElements;
		
		data = new int[capacity];
		
		for (int i = 0; i < ref.noOfElements; i++)
		{
			data[i] = ref.data[i];
		}
	}
	void Set::insert( int element )
	{
		for ( int i = 0; i < noOfElements; i++ )
		{
			if ( data[i] == element )
			{
				//cout << "Number not added , the element already exist" << endl;
				return;
			}
		}
		data[noOfElements] = element;
		noOfElements++;
	}
	void Set::remove( int element )
	{
		for ( int i = 0; i < noOfElements; i++ )
		{
			if ( data[i] == element )
			{
				for ( int j = i; j < noOfElements - 1; j++ )
				{
					data[j] = data[j + 1];
				}
				noOfElements--;
				return;
			}
		}
		cout << "Element not found in the set" << endl;
	}
	int Set::getCardinality() const
	{
		return noOfElements;
	}
	Set Set::calcUnion( Set &s2 )
	{
		Set result(capacity + s2.capacity);
		for ( int i = 0; i < noOfElements; i++ )
		{
			result.insert(data[i]);
		}
		for ( int i = 0; i < s2.noOfElements; i++ )
		{
			result.insert(s2.data[i]);
		}
		return result;
	}
	Set Set::calcIntersection(Set &s2)
	{
    	Set result( capacity );

    	for ( int i = 0; i < noOfElements; i++ )
    	{
      		if ( s2.isFound(data[i]) )
        	{
            	result.insert(data[i]);
        	}
    	}
    	
    	return result;
	}
	bool Set::isFound( const int element ) const
	{
		for ( int i = 0; i < noOfElements; i++ )
		{
			if ( data[i] == element )
			{
				return true;
			}
		}
		return false;
	}
	Set Set::calcSymmetricDifference( Set &s2 )
	{
		Set result(capacity + s2.capacity);
		for ( int i = 0; i < noOfElements; i++ )
		{
			if ( !s2.isFound(data[i]) )
			{
				result.insert(data[i]);
			}
		}
		for ( int i = 0; i < s2.noOfElements; i++ )
		{
			if ( !isFound(s2.data[i]) )
			{
				result.insert(s2.data[i]);
			}
		}
		return result;
	}
	void Set::DisplayData()
	{
		cout << "{ ";

    	for ( int i = 0; i < noOfElements; i++ )
    	{
        	cout << data[i];
        	if ( i != noOfElements - 1 )
        	{
        		cout << ", ";
			}
    	}
    	cout << " }" << endl;
	}
	void Set::reSize( int newcapacity )
	{
		int *temp = new int[newcapacity];
		
		for ( int i = 0; i < noOfElements; i++ )
		{
			temp[i] = data[i];
		}
		
		delete[] data;
		data = temp;
		capacity = newcapacity;
	}
	Set Set::calcDifference( Set &s2 )
	{
    	Set result(capacity);
    	
    	for ( int i = 0; i < noOfElements; i++ )
    	{
        	if ( !s2.isFound(data[i]) )
        	{
            	result.insert(data[i]);
        	}
    	}
		
		return result;
	}
	int Set::isMember ( const int &val )
	{
		return isFound( val );
	}
	int Set::isSubSet ( const Set &s2 )
	{
		for ( int i = 0; i < s2.noOfElements; i++ )
		{
			if ( !isFound (s2.data[i]) )
			{
				return 0;
			}
		}
		
		bool equal = true;
		
		for ( int i = 0; i < noOfElements; i++ )
		{
			if ( !s2.isFound(data[i]) )
			{
				equal = false;
				break;
			}	
		}
				
		if ( equal ) return 2;
		return 1;	
	}

int main()
{
	Set s1(8);
	s1.insert(1);
	s1.insert(2);
	s1.insert(3);
	s1.insert(4);
	s1.insert(5);
	s1.insert(6);
	s1.insert(7);
	s1.DisplayData();

	Set s2(7);
	s2.insert(6);
	s2.insert(7);
	s2.DisplayData();
	
	cout << endl << endl;
	cout << "Union : ";
	Set s3 = s1.calcUnion(s2);
	s3.DisplayData();
	
	cout << endl << endl;
	cout << "Intersection : ";
	Set s4 = s1.calcIntersection(s2);
	s4.DisplayData();
	
	cout << endl << endl;
	cout << "Symmetric Difference : ";
	Set s5 = s1.calcSymmetricDifference(s2);
	s5.DisplayData();
	
	cout << endl << endl;
	cout << "Sub-Set : ";
	int result = s1.isSubSet(s2);
	
	if ( result == 1 )
	{
		cout << "Set are Proper SubSet" << endl;
	}
	else if ( result == 2 )
	{
		cout << "Set are Im-Proper SubSet" << endl;
	}
	else
	{
		cout << "Not a SubSet" << endl;
	}
	
	cout << endl << endl;
	cout << "Difference : ";
	Set s7 = s1.calcDifference(s2);
	s7.DisplayData();

	return 0;
}