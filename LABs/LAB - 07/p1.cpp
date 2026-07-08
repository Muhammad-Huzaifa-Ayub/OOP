#include<iostream>
using namespace std;
class CString{
	
	private:
		
		char *str;
		int size;
		
		int getLen( const char* str ) const 
		{
			int len = 0;
			while ( str[len] != '\0' )
			{
				len++;
			}
			return len;
		}
		void getCopy ( char* dest, const char* src )
		{
			if ( dest == nullptr || src == nullptr ) return;
			int i = 0;
			
			while ( src[i] != '\0' )
			{
				dest[i] = src[i];
				i++;
			}
			dest[i] = '\0';
		}
		
	public:
		
		CString();
		CString ( char c );
		CString ( char * );
		CString ( const CString &str );
		~CString();
		void display() const;
		int find ( char *substr, int start = 0 ) const;
		int find ( char ch, int start = 0 ) const;
		int insert ( int index, char *substr );
		int insert ( int index, char ch );
		CString left ( int count ) const;
		CString right ( int count ) const;
		int remove ( int index , int count = 1 );
};

CString::CString()
{
	size = 0;
	str = nullptr;
}
CString::CString( char c )
{
	size = 2;
	str = new char[size];
	
	str[0] = c;
	str[1] = '\0';
}
CString::~CString()
{
	delete[] str;
	str = nullptr;
}
CString::CString( char *c )
{
	if ( c == nullptr )
	{
		str = nullptr;
		size = 0;
	}
	else 
	{
		size = getLen(c) + 1;
		str = new char[size];
		getCopy(str,c);
	}
}
void CString::display() const
{
	if ( str == nullptr ) return;
	else cout << "Data in the string is : " << str << endl << endl << endl;
}
CString::CString( const CString &s )
{
	if ( s.str == nullptr )
	{
		str = nullptr;
		size = 0;
	}
	else
	{
		size = s.size;
		str = new char[size];
		getCopy(str,s.str);
	}
}
int CString::find( char *substr, int start ) const
{
	if ( str == nullptr || substr == nullptr ) return -1;

	int len1 = getLen(str);
	int len2 = getLen(substr);

	for ( int i = start; i < len1 - len2; i++ )
	{
		int j = 0;
		while ( j < len2 && str[i + j] == substr[j] )
		{
			j++;
		}
		if ( j == len2 )
		{
			return i;
		}
	}
	return -1;
}
int CString::find( char ch, int start ) const
{
	if ( str == nullptr || ch == '\0' ) return -1;
	int i = 0;
	while ( str[i] != '\0' )
	{
		if ( str[i] == ch ) return i;
		i++;
	}
	return -1;
}
int CString::insert( int index, char *substr )
{
	if ( str == nullptr ) return -1;
	int len1 = getLen(str);
	int len2 = getLen(substr);

	if ( index < 0 ) index = 0;
	if ( index > len1 ) index = len1;

	char *Newstr = new char[len1 + len2 + 1];
	for ( int i = 0; i < index; i++ )
	{
		Newstr[i] = str[i];
	}
	for  ( int i = 0; i < len2; i++ )
	{
		Newstr[index + i] = substr[i];
	}
	for ( int i = index; i < len1; i++ )
	{
		Newstr[len2 + i] = str[i];
 	} 
	Newstr[len1 + len2 + 1] = '\0';

	delete[] str;
	str = Newstr;
	size = len1 + len2 + 1;

	return len1 + len2;
}
int CString::insert( int index, char ch )
{
	if ( str == nullptr ) return -1;
	int len = getLen(str);

	if ( index < 0 ) index = 0;
	if ( index > len ) index = len;

	char *Newstr = new char[len + 2];

	for ( int i = 0; i < index; i++ )
	{
		Newstr[i] = str[i];
	}
	Newstr[index] = ch;
	for ( int i = index; i < len; i++ )
	{
		Newstr[i + 1] = str[i];
	}
	Newstr[len + 1] = '\0';

	delete[] str;
	str = Newstr;
	size = len + 2;

	return len + 1;
}
CString CString::left( int count ) const
{
	if ( str == nullptr || count <= 0 ) return CString();
	int len = getLen(str);
	if ( count > len ) count = len;

	char *temp = new char [count + 1];
	for ( int i = 0; i < count; i++ )
	{
		temp[i] = str[i];
	}
	temp[count] = '\0';
	CString string( temp );
	delete[] temp; temp = nullptr;

	return string;
}
CString CString::right( int count ) const
{
	int len = getLen(str);
	if ( str == nullptr ) return CString();
	if ( count < 0 ) count = 0;
	if ( count >= len ) return CString();

	char *temp = new char[len - count  + 1];
	int j = 0;
	for ( int i = count; i < len; i++ )
	{
		temp[j] = str[i];
		j++;
	}
	temp[j] = '\0';
	CString string( temp );
	delete[] temp; temp = nullptr;

	return string;
}
int CString::remove ( int index , int count )
{
	int len = getLen(str);
	if ( str == nullptr )
	{
		return 0;
	}
	if ( index < 0 || count <= 0 || index >= len )
	{
		return len;
	}
	
	if ( index + count > len )
	{
		count = len - index;
	}
	
	int Newlen = len - count;
	char *Newstr = new char [Newlen + 1];
	
	
	for ( int i = 0; i < index; i++ )
	{
		Newstr[i] = str[i];
	}
	for ( int i = index)
	
	return len;
}



int main()
{
	CString obj1('A');
	obj1.display();

	char str1[] = "Apple is King of fruits";
	CString obj2(str1);
	obj2.display();

	CString obj3(obj2);
	obj3.display();

	char str2[] = "ple";
	cout << "int find ( char *substr, int start = 0 ) const" << endl;
	cout << obj3.find(str2) << endl << endl;

	char c = 'A';
	cout << "int find ( char ch, int start = 0 ) const" << endl;
	cout << obj3.find(c) << endl << endl;

	char str3[] = " not ";
	cout << "int insert ( int index, char *substr )" << endl;
	cout << obj3.insert(8,str3) << endl; obj3.display();

	cout << "int insert ( int index, char ch )" << endl;
	cout << obj3.insert(13,c) << endl; obj3.display();

	cout << "CString left( int count ) const" << endl;
	CString obj4 = obj3.left(19); cout << endl; obj4.display();

	cout << "CString right( int count ) const" << endl;
	CString obj5 = obj3.right(15); cout << endl; obj5.display();

	cout << "int remove ( int index , int count )" << endl;
	CString obj6(obj3); obj6.remove(6,4); obj6.display();



		return 0;
}