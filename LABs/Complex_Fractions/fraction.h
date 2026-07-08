#ifndef Fraction_H
#define Fraction_H

#include<iostream>

using namespace std;

class Fraction{
	
	private:
		int num;
		int den;
		
	public:

		int getNum() const;
		int getDen() const;
		void setNum( int num );
		void setDen( int den );
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

#endif
