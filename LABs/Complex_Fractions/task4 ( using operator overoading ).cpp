#include<iostream>

using namespace std;

class Fraction{
	
	private:
		int num;
		int den;
		
	public:
		
		Fraction( int num = 1, int den = 1 );
		Fraction reduce();
		Fraction operator + ( const Fraction &f );
		Fraction operator * ( const Fraction &f );
		Fraction operator / ( const Fraction &f );
		Fraction operator - ( const Fraction &f );
		void operator += ( const Fraction &f );
		void operator *= ( const Fraction &f );
		void operator /= ( const Fraction &f );
		void operator -= ( const Fraction &f );
		bool operator == ( const Fraction &f );
		bool operator != ( const Fraction &f );
		bool operator <= ( const Fraction &f);
		bool operator >= ( const Fraction &f );
		bool operator < ( const Fraction &f );
		bool operator > ( const Fraction &f );
		Fraction operator ++ ();
		Fraction operator ++ ( int );
		Fraction operator --();
		Fraction operator --( int );
		Fraction operator - ();
		operator double() const;
		
		friend ostream& operator << ( ostream &out, const Fraction &f );
};

Fraction::Fraction( int num, int den )
{
	this->num = num;
	if ( den == 0 ) 
    {
        cout << "Warning : Denominator cannot be zero. Setting to 1." << endl;
        this->den = 1;
    } 
    else 
    {
        this->den = den;
    }
}
ostream& operator << ( ostream &out, const Fraction &f )
{
	out << f.num << " / " << f.den;
	
	return out;
}
Fraction Fraction::reduce () 
{
	int i = 2;
	while ( i <= this->num )
	{
		if ( this->num % i == 0 && this->den % i == 0 )
		{
			this->den = this->den / i;
			this->num = this->num / i;
		}
		else
		{
			i++;
		}
	}
	return *this;
}
Fraction Fraction::operator + ( const Fraction &f )
{
	Fraction result;
	result.num = ( this->num * f.den ) + ( f.num * this->den );
	result.den = this->den * f.den;
	result.reduce();
	
	return result;
}
Fraction Fraction::operator - ( const Fraction &f )
{
	Fraction result;
	result.num = ( this->num * f.den ) - ( f.num * this->den );
	result.den = this->den * f.den;
	result.reduce();

	return result;
}
Fraction Fraction::operator * ( const Fraction &f )
{
	Fraction result;
	result.num = this->num * f.num;
	result.den = this->den * f.den;
	result.reduce();

	return result;
}
Fraction Fraction::operator / ( const Fraction &f )
{
	if ( f.num == 0 )
    {
        cout << "Error : Division by zero!" << endl;
        return Fraction(0, 1);
    }
    
	Fraction result;
	result.num = this->num * f.den;
	result.den = this->den * f.num;
	result.reduce();

	return result;
}
void Fraction::operator += ( const Fraction &f )
{
	this->num = ( this->num * f.den ) + ( f.num * this->den );
	this->den = this->den * f.den;
	this->reduce();
	
}
void Fraction::operator -= ( const Fraction &f )
{
	this->num = ( this->num * f.den ) - ( f.num * this->den );
	this->den = this->den * f.den;
	this->reduce();
	
}
void Fraction::operator *= ( const Fraction &f )
{
	this->num = this->num * f.num;
	this->den = this->den * f.den;
	this->reduce();

}
void Fraction::operator /= ( const Fraction &f )
{
	if ( f.num == 0 )
    {
        cout << "Error : Division by zero!" << endl;
        exit(1);
    }
    
	this->num = this->num * f.den;
	this->den = this->den * f.num;
	this->reduce();

}
bool Fraction::operator == ( const Fraction &f ) {
    return (this->num * f.den == f.num * this->den);
}

bool Fraction::operator != ( const Fraction &f ) {
    return !(*this == f);
}

bool Fraction::operator < ( const Fraction &f ) {
    return (this->num * f.den < f.num * this->den);
}

bool Fraction::operator > ( const Fraction &f ) {
    return (this->num * f.den > f.num * this->den);
}

bool Fraction::operator <= ( const Fraction &f ) {
    return (this->num * f.den <= f.num * this->den);
}

bool Fraction::operator >= ( const Fraction &f ) {
    return (this->num * f.den >= f.num * this->den);
}

Fraction Fraction::operator ++ ()
{
	this->num = this->num + this->den;
    this->reduce();
	
	return *this;
}
Fraction Fraction::operator ++  ( int )
{
	Fraction result = *this;
    this->num = this->num + this->den;
    this->reduce();
    
    return result;
}
Fraction Fraction::operator -- ()
{
	this->num = this->num - this->den;
    this->reduce();
	
	return *this;
}
Fraction Fraction::operator -- ( int )
{
	Fraction result = *this;
    this->num = this->num - this->den;
    this->reduce();
    
    return result;
}
Fraction Fraction::operator - ()
{
	Fraction result;
	
    result.num = this->num * -1; 
    result.den = this->den; 
    
    return result;
}
Fraction::operator double () const
{
	return (double)this->num / this->den;
}

int main()
{
	Fraction f1(24,36);
	Fraction f2(3,7);
	cout << endl << endl;
	
	
	Fraction f3;
	f3 = f1 + f2;
	cout << "Addition of Fractions = " << endl;
	cout << "Addition of "; cout << f1; cout << "  and  "; cout << f2; cout << "  is  : "; cout << f3; cout << endl;
	cout << endl << endl;
	

	Fraction f4;
	f4 = f1 - f2;
	cout << "Subtraction of Fractions = " << endl;
	cout << "Subtraction of "; cout << f1; cout << "  and  "; cout << f2; cout << "  is  : "; cout << f4; cout << endl;
	cout << endl << endl;


	Fraction f5;
	f5 = f1 * f2;
	cout << "Multiplication of Fractions = " << endl;
	cout << "Multiplication of "; cout << f1; cout << "  and  "; cout << f2; cout << "  is  : "; cout << f5; cout << endl;
	cout << endl << endl;
	
	
	Fraction f6;
	f6 = f1 / f2;
	cout << "Division of Fractions = " << endl;
	cout << "Division of "; cout << f1; cout << "  and  "; cout << f2; cout << "  is  : "; cout << f6; cout << endl;
	cout << endl << endl;
	
	
	cout << "void operator += ( const Fraction &f )" << endl;
	cout << "Subtraction of "; cout << f1; cout << "  and  "; cout << f2; f1 -= f2; cout << "  is  : "; cout << f1; cout << endl;
	cout << endl << endl;
	

	cout << "void operator -= ( const Fraction &f )" << endl;
	cout << "Subtraction of "; cout << f1; cout << "  and  "; cout << f2; f1 += f2; cout << "  is  : "; cout << f1; cout << endl;
	cout << endl << endl;


	cout << "void operator *= ( const Fraction &f )" << endl;
	cout << "Multiplication of "; cout << f1; cout << "  and  "; cout << f2; f1 *= f2; cout << "  is  : "; cout << f1; cout << endl;
	cout << endl << endl;
	
		
	cout << "void operator /= ( const Fraction &f )" << endl;
	cout << "Division of "; cout << f1; cout << "  and  "; cout << f2; f1 /= f2; cout << "  is  : "; cout << f1; cout << endl;
	cout << endl << endl;
	
	cout << "F1 is : "; cout << f1; cout << "  and  F2 is : "; cout << f2; cout << endl;
	
	cout << "bool operator == ( const Fraction &f )" << endl;
	if ( f1 == f2 ) cout << "Fractions are Equal" << endl;
	else cout << "Fractions are not Equal" << endl;
	cout << endl << endl;
	
	
	cout << "bool operator != ( const Fraction &f )" << endl;
	if ( f1 != f2 ) cout << "Fractions are not Equal" << endl;
	else cout << "Fractions are Equal" << endl;
	cout << endl << endl;
	
	cout << "bool operator <= ( const Fraction &f )" << endl;
	if ( f1 <= f2 ) cout << "F1 is less than or equal to F2" << endl;
	else cout << "F1 is not less than or equal to F2" << endl;
	cout << endl << endl;
	
	cout << "bool operator >= ( const Fraction &f )" << endl;
	if ( f1 >= f2 ) cout << "F1 is greater than or equal to F2" << endl;
	else cout << "F1 is not greater than or equal to F2" << endl;
	cout << endl << endl;
	
	cout << "bool operator < ( const Fraction &f )" << endl;
	if ( f1 < f2 ) cout << "F1 is less than F2" << endl;
	else cout << "F1 is not less than F2" << endl;
	cout << endl << endl;
	
	cout << "bool operator > ( const Fraction &f )" << endl;
	if ( f1 >  f2 ) cout << "F1 is greater than F2" << endl;
	else cout << "F1 is not greater than F2" << endl;
	cout << endl << endl;
	
	
	cout << "F1 is : "; cout << f1; cout << endl;
	cout << "Fraction operator ++ ()" << endl; 
	++f1;
	cout << f1; cout << endl << endl;
	
	
	cout << "F1 is : "; cout << f1; cout << endl;
	cout << "Fraction operator ++ ( int )" << endl; 
	f1++;
	cout << f1; cout << endl << endl;
	
	
	cout << "F1 is : "; cout << f1; cout << endl;
	cout << "Fraction operator -- ()" << endl; 
	--f1;
	cout << f1; cout << endl << endl;
	
	
	cout << "F1 is : "; cout << f1; cout << endl;
	cout << "Fraction operator -- ( int )" << endl; 
	f1--;
	cout << f1; cout << endl << endl;
	
	
	cout << "F1 is : "; cout << f1; cout << endl;
	cout << "Fraction operator - ()" << endl; 
	f1 = -f1;
	cout << f1; cout << endl << endl;
	cout << "F1 is : "; cout << f1; cout << endl;
	cout << "Fraction operator - ()" << endl; 
	f1 = -f1;
	cout << f1; cout << endl << endl;
	
	
	cout << "F2 is : "; cout << f2; cout << endl;
	cout << "Fraction operator - ()" << endl; 
	f2 = -f2;
	cout << f2; cout << endl << endl;
	cout << "F2 is : "; cout << f2; cout << endl;
	cout << "Fraction operator - ()" << endl; 
	f2 = -f2;
	cout << f2; cout << endl << endl;
	
	
	double v1 = f1;
	cout << "F1 in Decimal : " << v1 << endl;
	double v2 = f2;
	cout << "F2 in Decimal : " << v2 << endl;
	
	
	return 0;
}