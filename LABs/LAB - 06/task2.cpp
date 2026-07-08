#include <iostream>
#include <cstring>

using namespace std;

class Set
{

private:
	int *data;
	int capacity;
	int noOfElements;

public:
	Set(int cap = 5)
	{
		if (cap <= 0)
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
	~Set()
	{
		delete[] data;
		data = nullptr;
	}
	Set(const Set &ref)
	{
		capacity = ref.capacity;
		noOfElements = ref.noOfElements;
		data = new int[capacity];
		for (int i = 0; i < ref.noOfElements; i++)
		{
			data[i] = ref.data[i];
		}
	}
	void insert(int element)
	{
		for (int i = 0; i < noOfElements; i++)
		{
			if (data[i] == element)
			{
				cout << "Number not added, Insufficient capacity or , the element already exist" << endl;
				return;
			}
		}
		data[noOfElements] = element;
		noOfElements++;
	}
	void remove(int element)
	{
		for (int i = 0; i < noOfElements; i++)
		{
			if (data[i] == element)
			{
				for (int j = i; j < noOfElements; j++)
				{
					data[j] = data[j + 1];
				}
				noOfElements--;
				return;
			}
		}
		cout << "Element not found in the set" << endl;
	}
	int getCardinality() const
	{
		return noOfElements;
	}
	Set calcUnion(Set &s2)
	{
		Set result(capacity + s2.capacity);
		for (int i = 0; i < noOfElements; i++)
		{
			result.insert(data[i]);
		}
		for (int i = 0; i < s2.noOfElements; i++)
		{
			result.insert(s2.data[i]);
		}
		return result;
	}
	Set calcIntersection(Set &s2)
	{
		Set result(capacity + s2.capacity);
		for (int i = 0; i < noOfElements; i++)
		{
			for (int j = 0; j < s2.noOfElements; j++)
			{
				if (data[i] == s2.data[j])
				{
					result.insert(data[i]);
				}
			}
		}
		return result;
	}
	bool isFound(const int element) const
	{
		for (int i = 0; i < noOfElements; i++)
		{
			if (data[i] == element)
			{
				return true;
			}
		}
		return false;
	}
	Set calcSymmetricDifference(Set &s2)
	{
		Set result(capacity + s2.capacity);
		for (int i = 0; i < noOfElements; i++)
		{
			if (!s2.isFound(data[i]))
			{
				result.insert(data[i]);
			}
		}
		for (int i = 0; i < s2.noOfElements; i++)
		{
			if (!isFound(s2.data[i]))
			{
				result.insert(s2.data[i]);
			}
		}
		return result;
	}
	void DisplayData()
	{
		cout << endl
			 << "Data in the Set is : ";
		for (int i = 0; i < noOfElements; i++)
		{
			cout << data[i] << ",";
		}
		cout << "\b" << endl;
	}
};
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
	s1.insert(8);

	s1.DisplayData();

	Set s2(7);
	s2.insert(6);
	s2.insert(7);
	s2.insert(8);
	s2.insert(9);
	s2.insert(10);
	s2.insert(11);
	s2.insert(12);

	Set s3 = s1.calcUnion(s2);
	s3.DisplayData();

	Set s4 = s1.calcIntersection(s2);
	s4.DisplayData();

	Set s5 = s1.calcSymmetricDifference(s2);
	cout << "Symmetric Difference: ";
	s5.DisplayData();

	return 0;
}