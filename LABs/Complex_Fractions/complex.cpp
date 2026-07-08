
#include "complex.h"

ComplexNumber::ComplexNumber( Fraction real, Fraction imag )
{
	if ( real.getNum() == 0 && real.getDen() == 1 && imag.getNum() == 0 && imag.getDen() == 1 ) 
	{
		this->real.setNum(0);
		this->real.setDen(0);
		this->imag.setNum(0);
		this->imag.setDen(0);
	}
	else
	{
		this->real = real;
		this->imag = imag;
	}
}

void ComplexNumber::display() const
{
	cout << real;
	if ( imag < 0 )
	{
		cout << imag << "i";
	}
	else
	{
		cout << "+" << imag << "i";
	}
}

ComplexNumber ComplexNumber::operator + ( const ComplexNumber &ref )
{
	ComplexNumber result;
	result.real = this->real + ref.real;
	result.imag = this->imag + ref.imag;
	
	return result;	
}

ComplexNumber ComplexNumber::operator - ( const ComplexNumber &ref )
{
	ComplexNumber result;
	result.real = this->real - ref.real;
	result.imag = this->imag - ref.imag;
	
	return result;	
}

ComplexNumber ComplexNumber::operator * ( const ComplexNumber &ref )
{
	ComplexNumber result;
	result.real = ( this->real * ref.real ) - ( this->imag * ref.imag );
	result.imag = ( this->imag * ref.real ) + ( this->real * ref.imag );
	
	return result;	
}

ComplexNumber ComplexNumber::operator / ( const ComplexNumber &ref )
{
    ComplexNumber result;

    Fraction denominator = (ref.real * ref.real) + (ref.imag * ref.imag);

    result.real = ( ( this->real * ref.real ) + ( this->imag * ref.imag ) ) / denominator;
    result.imag = ( ( this->imag * ref.real ) - ( this->real * ref.imag ) ) / denominator;

    return result;
}
