#include<iostream>

using namespace std;

class CString{
	
	private :
		char *str;
		int size;
		
		int getLength( const char* str ) const
		{	
			int count = 0;
			while ( str[count] != '\0' )
			{
				count++;
			}
			return count;
		}
		void getCopy ( char* dest, const char* src ) const
		{
			if  ( src == nullptr || dest == nullptr ) return;

			int i = 0;
			
			while ( src[i] != '\0' ) 
			{
				dest[i] = src[i];
				i++;
			}
			
			dest[i] = '\0';
		}
		int compare ( const char *s1, const char *s2 ) const
		{
			if ( s1 == nullptr && s2 == nullptr ) return 1;
			if ( s1 == nullptr || s2 == nullptr ) return 0;

			int i = 0;
			while ( s1[i] != '\0' && s2[i] != '\0' )
			{
				if ( s1[i] != s2[i] )
				{
					return 0; 
				}
				i++;
			}

			if ( s1[i] == '\0' && s2[i] == '\0' )
			{
				return 1;
			}

			return 0; 
		}
		void concat ( char *dest, const char *src ) const
		{
			int destLen = 0;
			while ( dest[destLen] != '\0' )
			{
				destLen++; 
			}

			int i = 0;
			while ( src[i] != '\0' )
			{
				dest[destLen + i] = src[i];
				i++;
			}

			dest[destLen + i] = '\0';
		}

	public :
		
		CString();
		CString( char c );
		CString ( const char *s );
		CString ( const CString & );
		CString& operator = ( const CString & ref );  // operator = 
		~CString();
		int getLength() const;
		void display () const;
		int find ( char *substr, int start = 0 ) const;
		int find ( char ch, int start = 0 ) const ;
		int insert ( int index, const char *substr );
		int insert ( int index, const char ch );
		CString left ( int count ) const;
		CString right ( int count ) const;
		int remove( int index, int count = 1); 
		int remove ( char ch );
		void replace ( char newChar  );
		int replace ( char oldChar, char newChar );
		int replace ( const char* oldStr, const char* newStr );
		void trim ();
		void trimLeft();
		void trimRight();
		void makeUpper();
		void makeLower();
		void reverse();
		void reSize( int add );
		CString operator + ( const CString &s2 ) const;  // operator +
		CString operator + ( const char* s2 ) const;    // operator +
		void concatEqual ( const CString &s2 );
		void concatEqual ( const char *s2 );
		void operator += ( const CString &s2 );  // operator +=
		void operator += ( const char *s2 );  //operator +=
		int isEqual ( const CString &s2 ) const;
		int isEqual ( char *s2 ) const;
		void input ();
		char &at ( int index );
		int isEmpty();
					
};

int CString::getLength() const
{	
	int count = 0;
	while ( str[count] != '\0' )
	{
		count++;
	}
	return count;
}

CString::CString()
{
	str = nullptr;
	size = 0;
}

CString::CString ( char c )
{
	size = 2;
	str = new char [size];
	
	str[0] = c;
	str[1] = '\0';
}
CString::CString ( const char *s )
{
	if ( s == nullptr )
	{
		str = nullptr;
		size = 0;
	}
	else 
	{
		size = getLength(s) + 1;
		str = new char[size];
		
		getCopy(str,s);
	}	
}

CString::CString ( const CString & obj )
{
	if ( obj.str == nullptr )
	{
		str = nullptr;
		size = 0;
	}
	else
	{
		size = obj.size;
		str = new char[size];
		getCopy(str,obj.str);
	}
}

CString& CString::operator = ( const CString & ref )  // operator =
{
	return *this;
}

CString::~CString()
{
    delete[] str;
}


void CString::display() const
{
	cout << str << endl;
}

int CString::find ( char *substr, int start ) const 
{
	int len1 = getLength(str);
    int len2 = getLength(substr);

    for ( int i = start; i <= len1 - len2; i++ )
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

int CString::find ( char ch, int start ) const
{
	if ( !str ) return -1;
	
	int len = getLength(str);
	
	for ( int i = start; i < len; i++ )
	{
		if ( str[i] == ch )
		{
			return i;
		}
	}
	
	return -1;
}

int CString::insert(int index, const char *substr)
{
    if ( !substr ) return -1;

    int len1 = getLength(str);
    int len2 = getLength(substr);

    if (index < 0) index = 0;
    if (index > len1) index = len1;

    char *newStr = new char[len1 + len2 + 1];

    for ( int i = 0; i < index; i++ )
    {
    	newStr[i] = str[i];
	}

    for ( int i = 0; i < len2; i++ )
    {
    	newStr[index + i] = substr[i];  
	}
        
    for ( int i = index; i < len1; i++ )
    {
    	newStr[len2 + i] = str[i];
	}

    newStr[len1 + len2] = '\0';

    delete[] str; 
    str = newStr;
    size = len1 + len2 + 1;

    return len1 + len2;
}

int CString::insert( int index, const char ch )
{
	int len = getLength(str);
	
	if ( index < 0 ) index = 0;
    if ( index > len ) index = len;
    
    char *newstr = new char[len + 2];
    
    for ( int i = 0; i < index; i++ )
    {
    	newstr[i] = str[i];
	}
	
	newstr[index] = ch;
	
	for ( int i = index; i < len; i++ )
	{
		newstr[i + 1] = str[i];
	}
	
	newstr[len + 1] = '\0';
	
	delete[] str;
	
	str = newstr;
	size = len + 2;
	 
	return len + 1;
}

CString CString::left ( int count ) const
{
	if ( count <= 0 || !str )
	{
		return CString("");
	}

    int len = getLength(str);
    if ( count > len ) count = len;
    
	char *newstr = new char[count + 1];
	
	for ( int i = 0; i < count; i++ )
	{
		newstr[i] = str[i];
	}
	
	newstr[count] = '\0'; 

    CString result( newstr ); 
    delete[] newstr;        

    return result;	
}

CString CString::right ( int count ) const
{
	if ( count <= 0 || !str )
	{
		return CString("");
	}

    int len = getLength(str);
    if ( count > len ) count = len;
    
    int start = len - count;
    
	char *newstr = new char[count + 1];
	
	for ( int i = 0; i < count; i++ )
	{
		newstr[i] = str[start + i];
	}
	
	newstr[count] = '\0'; 

    CString result( newstr ); 
    delete[] newstr;        

    return result;	
}

int CString::remove ( int index, int count )
{
	int currentLen = getLength(this->str);
	
	if ( index < 0 || index >= currentLen || count <= 0 )
	{
		return currentLen;
	}
	
	if ( index + count > currentLen )
	{
		count = currentLen - index;
	}
	for ( int i = index; i <= currentLen - count; i++ )
	{
		this->str[i] = this->str[i + count];
	}
	return getLength(this->str);
}

int CString::remove( char ch ) 
{
    if ( this->str == nullptr ) return 0;

    int removedCount = 0;
    int i = 0;

    while ( this->str[i] != '\0' ) 
    {
        if ( this->str[i] == ch ) 
        {
            int j = i;
            while ( this->str[j] != '\0' ) 
            {
                this->str[j] = this->str[j + 1];
                j++;
            }
            removedCount++;
        } 
        else 
        {
            i++;
        }
    }

    return removedCount;
}

void CString::replace ( char newChar ) 
{
    if ( this->str == nullptr ) return;

    int i = 0;
    
    while ( this->str[i] != '\0' ) 
    {
        this->str[i] = newChar;
        i++;
    }
}

int CString::replace ( char oldChar, char newChar ) 
{
    if ( this->str == nullptr ) return 0;

    int count = 0;
    int i = 0;
    while ( this->str[i] != '\0' ) 
    {
        if ( this->str[i] == oldChar ) 
        {
            this->str[i] = newChar;
            count++;
        }
        i++;
    }
    return count;
}

int CString::replace ( const char* oldStr, const char* newStr ) 
{
    if ( this->str == nullptr || oldStr == nullptr || newStr == nullptr ) return 0;

    int count = 0;
    int lenOld = getLength(oldStr);
    int lenMain = getLength(this->str);

    for ( int i = 0; i <= lenMain - lenOld; i++ ) 
    {
        bool match = true;
        for ( int j = 0; j < lenOld; j++ ) {
            if ( this->str[i + j] != oldStr[j] ) {
                match = false;
                break;
            }
        }

        if (match) 
        {
            for ( int j = 0; j < lenOld; j++ ) {
                this->str[i + j] = newStr[j];
            }
            count++;
            i += lenOld - 1;
        }
    }
    return count;
}

void CString::trim()
{
    trimLeft();
    trimRight();
}

void CString::trimLeft()
{
    if ( !str )
	{
        return;
    }

    int len = getLength(str);
    int start = 0;

    while ( start < len && str[start] == ' ' )
	{
        start++;
    }

    if ( start == 0 )
	{
        return;
    }

    int newLen = len - start;
    char *newstr = new char[newLen + 1];

    for ( int i = 0; i < newLen; i++ )
	{
        newstr[i] = str[start + i];
    }

    newstr[newLen] = '\0';

    delete[] str;
    str = newstr;
    size = newLen + 1;
}

void CString::trimRight()
{
    if ( !str )
	{
        return;
    }

    int len = getLength(str);
    int end = len - 1;

    while ( end >= 0 && str[end] == ' ' )
	{
        end--;
    }

    if ( end == len - 1 )
	{
        return;
    }

    int newLen = end + 1;
    char *newstr = new char[newLen + 1];

    for ( int i = 0; i < newLen; i++ )
	{
        newstr[i] = str[i];
    }

    newstr[newLen] = '\0';

    delete[] str;
    str = newstr;
    size = newLen + 1;
}

void CString::makeUpper()
{
    if ( !str )
	{
        return;
    }

    int len = getLength(str);

    for ( int i = 0; i < len; i++ )
	{
        if ( str[i] >= 'a' && str[i] <= 'z' )
		{
            str[i] = str[i] - 32;
        }
    }
}

void CString::makeLower()
{
    if ( !str )
	{
        return;
    }

    int len = getLength(str);

    for ( int i = 0; i < len; i++ )
	{
        if ( str[i] >= 'A' && str[i] <= 'Z' )
		{
            str[i] = str[i] + 32;
        }
    }
}

void CString::reverse()
{
    if ( !str )
	{
        return;
    }

    int len = getLength(str);

    for ( int i = 0; i < len / 2; i++ )
	{
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

void CString::reSize ( int add )
{
    if ( add <= 0 )
	{
        return;
    }

    int oldLen = 0;
    if (str)
	{
        oldLen = getLength(str);
    }

    int newSize = size + add;
    char *newstr = new char[newSize];

    if (str)
	{
        getCopy(newstr, str);
        delete[] str;
    }
	else
	{
        newstr[0] = '\0';
    }

    str = newstr;
    size = newSize;
}

CString CString::operator + ( const CString &s2 ) const  // operator +
{
    if (!str && !s2.str) return CString("");
    if (!str) return CString(s2.str);
    if (!s2.str) return CString(str);

    int len1 = getLength(this->str);
    int len2 = getLength(s2.str);

    char *newstr = new char[len1 + len2 + 1];

    getCopy(newstr, this->str);
    concat(newstr, s2.str);        

    CString result(newstr);
    delete[] newstr; 

    return result;
}

CString CString::operator + ( const char* s2 ) const  // operator +
{
	if (!str && !s2) return CString("");
    if (!str) return CString(s2);
    if (!s2) return CString(str);

    int len1 = getLength(this->str);
    int len2 = getLength(s2);

    char *newstr = new char[len1 + len2 + 1];

    getCopy(newstr, this->str);
    concat(newstr, s2);        

    CString result(newstr);
    delete[] newstr; 

    return result;
	
}

void CString::concatEqual ( const CString &s2 )
{
    if ( !s2.str )
	{
        return;
    }

    if ( !str )
	{
        size = getLength(s2.str) + 1;
        str = new char[size];
        getCopy(str, s2.str);
        return;
    }

    int len1 = getLength(str);
    int len2 = getLength(s2.str);

    char *newstr = new char[len1 + len2 + 1];
    getCopy(newstr, str);
    concat(newstr, s2.str);

    delete[] str;
    str = newstr;
    size = len1 + len2 + 1;
}

void CString::operator += ( const CString &s2 ) // operator +=
{
    if ( !s2.str )
	{
        return;
    }

    if ( !str )
	{
        size = getLength(s2.str) + 1;
        str = new char[size];
        getCopy(str, s2.str);
        return;
    }

    int len1 = getLength(str);
    int len2 = getLength(s2.str);

    char *newstr = new char[len1 + len2 + 1];
    getCopy(newstr, str);
    concat(newstr, s2.str);

    delete[] str;
    str = newstr;
    size = len1 + len2 + 1;
}

void CString::concatEqual ( const char *s2 ) 
{
    if ( !s2 ) {
        return;
    }

    if ( !str )
	{
        size = getLength(s2) + 1;
        str = new char[size];
        getCopy(str, s2);
        return;
    }

    int len1 = getLength(str);
    int len2 = getLength(s2);

    char *newstr = new char[len1 + len2 + 1];
    getCopy(newstr, str);
    concat(newstr, s2);

    delete[] str;
    str = newstr;
    size = len1 + len2 + 1;
}

void CString::operator += ( const char *s2 )   // operator +=
{
    if ( !s2 ) {
        return;
    }

    if ( !str )
	{
        size = getLength(s2) + 1;
        str = new char[size];
        getCopy(str, s2);
        return;
    }

    int len1 = getLength(str);
    int len2 = getLength(s2);

    char *newstr = new char[len1 + len2 + 1];
    getCopy(newstr, str);
    concat(newstr, s2);

    delete[] str;
    str = newstr;
    size = len1 + len2 + 1;
}

int CString::isEqual ( const CString &s2 ) const
{
    if ( !str && !s2.str )
	{
        return 0;
    }
    if ( !str )
	{
        return -1;
    }
    if ( !s2.str )
	{
        return 1;
    }

    return compare(str, s2.str);
}

int CString::isEqual ( char *s2 ) const
{
    if ( !str && !s2 )
	{
        return 0;
    }
    if ( !str )
	{
        return -1;
    }
    if ( !s2 )
	{
        return 1;
    }

    return compare(str, s2);
}

void CString::input()
{
    char buffer[1000];
    cin.getline(buffer, 1000);

    delete[] str;

    size = getLength(buffer) + 1;
    str = new char[size];
    getCopy(str, buffer);
}

char& CString::at ( int index )
{
    return str[index];
}

int CString::isEmpty()
{
    if ( !str || getLength(str) == 0 )
	{
        return 0;
    }
	else
	{
        return 1;
    }
}

int main()
{
	char c = 'A';
	char *char_ptr = &c;
	string str = "Hello!";
	string *str_ptr = &str;

	CString obj1;      
	CString obj2(c);    
	CString obj3( char_ptr );   
	CString obj4 = obj3;     // operator =
	
	cout << endl << endl;
	int len = obj4.getLength();
	cout << "length of string : " << len << endl;
	
	cout << endl << endl;
	obj4.display();
	
	cout << endl << endl;
	CString obj5("Hello World");
	char sub1[] = "World";
	char sub2[] = "Hello";
	char sub3[] = "ABC";
	cout << "Index of 'World' : " << obj5.find(sub1) << endl;
    cout << "Index of 'Hello' : " << obj5.find(sub2) << endl;
    cout << "Index of 'ABC'   : " << obj5.find(sub3) << endl;
    cout << "Search 'World' starting from index 3 : " << obj5.find(sub1,3) << endl;
    len = obj5.getLength();
	cout << "length of string : " << len << endl;
    
    cout << endl << endl;
    cout << "Index of 'o' : " << obj5.find('o') << endl;          
    cout << "Index of 'W' : " << obj5.find('W') << endl;          
    cout << "Index of 'z' : " << obj5.find('z') << endl;         
    cout << "Index of 'o' starting at index 5 : " << obj5.find('o', 5) << endl; 
    
    cout << endl << endl;
    CString obj6("Hello");
	cout << "Original: "; obj6.display();
	obj6.insert(6, "World");
	cout << "After insert: "; obj6.display();
	
	cout << endl << endl;
    CString obj7("Hello");
	cout << "Original: "; obj7.display();
	obj7.insert(6, 'W');
	cout << "After insert: "; obj7.display();
	
	cout << endl << endl;
	cout << "left side characters index based : " << endl;
	CString obj8 = obj6.left(5);
	obj8.display();
	
	cout << endl << endl;
	cout << "right side characters index based : " << endl;
	CString obj9 = obj6.right(5);
	obj9.display();
	len = obj9.getLength();
	cout << "length of string : " << len << endl;
	
	cout << endl << endl;
	cout << "remove characters index based : " << endl;
	CString obj10("Hello World");
	cout << "Original: "; obj10.display();
	obj10.remove(6, 3);
	cout << "After remove : "; obj10.display();
	
	cout << endl << endl;
	cout << "remove single character index based : " << endl;
	CString obj11("Hello World");
	cout << "Original: "; obj11.display();
	obj11.remove('d');
	cout << "After remove : "; obj11.display();
	
	cout << endl << endl;
	cout << "replace ( char newChar ) : " << endl;
	CString obj12('H');
	cout << "Original: "; obj12.display();
	obj12.replace('W');
	cout << "After replace : "; obj12.display();
	
	cout << endl << endl;
	cout << "replace ( char oldChar, char newChar ) : " << endl;
	CString obj13("Hello Hello");
	cout << "Original: "; obj13.display();
	obj13.replace('H','W');
	cout << "After replace : "; obj13.display();
	
	cout << endl << endl;
	cout << "replace ( const char* oldStr, const char* newStr ) : " << endl;
	CString obj14("Hello Hello");
	cout << "Original: "; obj14.display();
	obj14.replace("Hello Hello", "World World");
	cout << "After replace : "; obj14.display();
	
	cout << endl << endl;
	cout << "void trim() : " << endl;
	CString obj15("       Hello World       ");
	cout << "Original:"; obj15.display();
	obj15.trim();
	cout << "After  :"; obj15.display();
	
	cout << endl << endl;
	cout << "void trimLeft() : " << endl;
	CString obj16("       Hello World");
	cout << "Original:"; obj16.display();
	obj16.trimLeft();
	cout << "After  :"; obj16.display();
	
	cout << endl << endl;
	cout << "void trimRight() : " << endl;
	CString obj17("Hello World          ");
	cout << "Original:"; obj17.display(); 
	obj17.trimRight();
	cout << "After  :"; obj17.display();
	
	cout << endl << endl;
	cout << "void makeUpper() : " << endl;
	CString obj18("hello world");
	cout << "Original: "; obj18.display(); 
	obj18.makeUpper();
	cout << "After  : "; obj18.display();
	
	cout << endl << endl;
	cout << "void makeLower() : " << endl;
	CString obj19("HELLO WORLD");
	cout << "Original :"; obj19.display(); 
	obj19.makeLower();
	cout << "After  : "; obj19.display();
	
	cout << endl << endl;
	cout << "void reverse() : " << endl;
	CString obj20("Hello World");
	cout << "Original :"; obj20.display(); 
	obj20.reverse();
	cout << "After  : "; obj20.display();
	
	cout << endl << endl;
	cout << "void reSize( int add ) : " << endl;
	CString obj21("Hello World");
	cout << "Original :"; obj21.display(); 
	obj21.reSize(20);
	cout << "Resized the Object" << endl;
	
	cout << endl << endl;
	cout << "CString operator + ( const CString& s2 ) const : " << endl;  // operator +
	CString obj22("Hello ");
    CString obj23("World");
    cout << "String 1: "; obj22.display();
    cout << "String 2: "; obj23.display();
    CString obj24 = obj22 + obj23;
    cout << "After Concat ( s1 + s2 ) : ";
    obj24.display(); cout << endl;
    
    cout << endl << endl;
	cout << "CString operator + ( const char* s2 ) const : " << endl;  // operator +
	CString object22("Hello ");
    CString object23("World");
    cout << "String 1: "; object22.display();
    cout << "String 2: "; object23.display();
    CString object24 = object22 + object23;
    cout << "After Concat ( s1 + s2 ) : ";
    obj24.display(); cout << endl;
    
    cout << endl << endl;
    cout << "void operator += ( const CString& s2 ) : " << endl;  // operator +=
	CString obj25("Hello ");
    CString obj26("World");
    cout << "String 1: "; obj25.display();
    cout << "String 2: "; obj26.display();
    obj25 += obj26;
    cout << "After Concat ( s1 + s2 ) : ";
    obj25.display(); cout << endl;
    
    cout << endl << endl;
    cout << "void operator += ( const char *s2 ) : " << endl;  // operator +=
    CString obj27("Programming"); 
    cout << "Original: "; obj27.display();
    char temp[] = " is Fun!"; 
    obj27 += temp; 
    cout << "After concatEqual (char*): ";
	obj27.display(); cout << endl;
	
	cout << endl << endl;
	cout << "int isEqual ( const CString &s2 ) const :" << endl;
    CString obj28("Programming");
    CString obj29("Programming");
    cout << "String 1: "; obj28.display();
    cout << "String 2: "; obj29.display();
    if ( obj28.isEqual(obj29) ) cout << "Result: obj28 is equal to obj29 " << endl;
	else cout << "Result: obj28 is NOT equal to obj29 " << endl;
		
	cout << endl << endl;
    cout << "int isEqual ( char *s2 ) const :" << endl;
    char tmp[] = "Programming";
    char check[] = "Programming";
    CString obj30(tmp);
    cout << "String in obj30 is : "; obj30.display();
    if ( obj30.isEqual(check) == 1 ) cout << "Result: obj30 is equal to 'Programming' " << endl;
    else cout << "Result: obj30 is NOT equal to 'Programming' " << endl;
	
	cout << endl << endl;
    cout << "void input() : " << endl;
    CString obj31;
    cout << "Please enter a string : ";
    obj31.input(); 
    cout << "The string you entered is : "; obj31.display();
	
	cout << endl << endl;
    cout << "char& at( int index ) : " << endl;
    CString obj32("Hello");
    cout << "Original : "; obj32.display();
    cout << "Character at index 1 : " << obj32.at(1) << endl;
    obj32.at(1) = 'a'; 
    cout << "After modifying index 1 to 'a' : "; obj32.display();
    
    cout << endl << endl;
    cout << "int isEmpty() : " << endl;
    CString obj33("Task Done");
    cout << "Testing with 'Task Done' : " << obj33.isEmpty() << endl;
    CString obj34("");
    cout << "Testing with empty string : " << obj34.isEmpty() << endl;
	
	return 0;
}