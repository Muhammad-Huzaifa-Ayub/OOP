#include<iostream>
#include<string>
#include<cstring>

using namespace std;

bool palindrome(char ch[],int len)
{
	for ( int i = 0; i < len / 2; i++ )
	{
		if ( ch[i] != ch[len - i - 1] )
		{
			return false;
		}
	}
	return true;
}

int main()
{
	
	char ch[50];
	
	cout << "Enter an array of characters : ";
	cin >> ch;
	
	int len = strlen(ch);
	
	
	
	if ( palindrome(ch,len) )
	{
		cout << "It is palindrome.";
	}
	else cout << "It is not palindrome.";
	
	return 0;
}