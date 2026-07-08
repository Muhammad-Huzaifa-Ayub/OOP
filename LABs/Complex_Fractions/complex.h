#ifndef Complex_H
#define Complex_H

#include<iostream>
#include "fraction.h"

using namespace std;

class ComplexNumber{
	
	private:
		Fraction real;
		Fraction imag;
	
	public:
		
		ComplexNumber( Fraction real = 0, Fraction imag = 0 );
		void display() const;
		ComplexNumber operator + ( const ComplexNumber &ref );
		ComplexNumber operator - ( const ComplexNumber &ref );
		ComplexNumber operator * ( const ComplexNumber &ref );
		ComplexNumber operator / ( const ComplexNumber &ref );
};

#endif

