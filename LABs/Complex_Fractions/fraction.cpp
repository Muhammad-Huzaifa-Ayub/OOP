
#include "fraction.h"

int Fraction::getNum() const
{
	return this->num;
}
int Fraction::getDen() const
{
	return this-> den;
}
void Fraction::setNum( int num )
{
	this->num = num;
}
void Fraction::setDen( int den )
{
	this->den = den;
}
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
	if ( f.num == 0 && f.den == 0 )
	{
		out << f.num;
	}
	else if ( f.den == 1 )
	{
		out << f.num;
	}
	else
	{
		out << f.num << "/" << f.den;
	}
	
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
