#include<iostream>

using namespace std;

class ComplexNumber{
	
	private:
		double real;
		double imag;
	
	public:
		
		ComplexNumber( double real, double imag );
		ComplexNumber operator + ( const ComplexNumber &ref );
		ComplexNumber operator - ( const ComplexNumber &ref );
		ComplexNumber operator * ( const ComplexNumber &ref );
		ComplexNumber operator / ( const ComplexNumber &ref );
		
		friend ostream& operator << ( ostream &out, const ComplexNumber &ref );
};

ComplexNumber::ComplexNumber( double real = 0, double imag = 0 )
{
	this->real = real;
	this->imag = imag;
}

ostream& operator << ( ostream &out, const ComplexNumber &ref )
{
	out << ref.real;
	if ( ref.imag < 0 )
	{
		out << ref.imag << "i";
	}
	else
	{
		out << "+" << ref.imag << "i";
	}
	return out;
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

    double denominator = (ref.real * ref.real) + (ref.imag * ref.imag);

    result.real = ( ( this->real * ref.real ) + ( this->imag * ref.imag ) ) / denominator;
    result.imag = ( ( this->imag * ref.real ) - ( this->real * ref.imag ) ) / denominator;

    return result;
}

int main()
{
	ComplexNumber n1(3,-8);
	ComplexNumber n2(7,2);
	
	ComplexNumber n3;
	n3 = n1 + n2;
	cout << "Addtion of Complex Numbers = " << endl;
	cout << "Addtion of "; cout << n1; cout << " and "; cout << n2; cout << " is : "; cout << n3; cout << endl;
	cout << endl << endl;
	
	ComplexNumber n4;
	n4 = n1 - n2;
	cout << "Subtraction of Complex Numbers = " << endl;
	cout << "Subtraction of "; cout << n1; cout << " and "; cout << n2; cout << " is : "; cout << n4; cout << endl;
	cout << endl << endl;
	
	ComplexNumber n5;
	n5 = n1 * n2;
	cout << "Multiplications of Complex Numbers = " << endl;
	cout << "Multiplication of "; cout << n1; cout << " and "; cout << n2; cout << " is : "; cout << n5; cout << endl;
	cout << endl << endl;
	
	ComplexNumber n6;
	n6 = n1 / n2;
	cout << "Division of Complex Numbers = " << endl;
	cout << "Division of "; cout << n1; cout << " and "; cout << n2; cout << " is : "; cout << n6; cout << endl;
	cout << endl << endl;
	
	return 0;
}