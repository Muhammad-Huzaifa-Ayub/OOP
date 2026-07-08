#include "FeetInches.h"

FeetInches::FeetInches( int f , int i )
{
    feet = f;
    inches = i;
    simplify();
}

// Copy constructor
FeetInches::FeetInches(const FeetInches &right)
{
    feet = right.feet;
    inches = right.inches;
    simplify();
}

// Mutator function to set feet
void FeetInches::setFeet(int f)
{
    feet = f;
}

// Mutator function to set inches
void FeetInches::setInches(int i)
{
    inches = i;
    simplify();
}

// Accessor function to get feet
int FeetInches::getFeet() const
{
    return feet;
}

// Accessor function to get inches
int FeetInches::getInches() const
{
    return inches;
}

// Overloaded + operator
FeetInches FeetInches::operator+(const FeetInches &right)
{
    FeetInches temp;

    temp.inches = inches + right.inches;
    temp.feet = feet + right.feet;
    temp.simplify();

    return temp;
}

// Overloaded - operator
FeetInches FeetInches::operator-(const FeetInches &right)
{
    FeetInches temp;

    temp.inches = inches - right.inches;
    temp.feet = feet - right.feet;
    temp.simplify();

    return temp;
}

// Overloaded * operator
FeetInches FeetInches::operator*(const FeetInches &right)
{
    FeetInches temp;

    temp.inches = inches * right.inches;
    temp.feet = feet * right.feet;
    temp.simplify();

    return temp;
}

// Overloaded prefix ++ operator
FeetInches FeetInches::operator++()
{
    ++inches;
    simplify();

    return *this;
}

// Overloaded postfix ++ operator
FeetInches FeetInches::operator++(int)
{
    FeetInches temp(feet, inches);

    inches++;
    simplify();

    return temp;
}

// Overloaded prefix -- operator
FeetInches FeetInches::operator--()
{
    --inches;
    simplify();

    return *this;
}

// Overloaded postfix -- operator
FeetInches FeetInches::operator--(int)
{
    FeetInches temp(feet, inches);

    inches--;
    simplify();

    return temp;
}

// Overloaded > operator
bool FeetInches::operator>(const FeetInches &right) const
{
    bool status;

    if (feet > right.feet)
        status = true;
    else if (feet == right.feet && inches > right.inches)
        status = true;
    else
        status = false;

    return status;
}

// Overloaded < operator
bool FeetInches::operator<(const FeetInches &right) const
{
    return !(*this > right);
}

// Overloaded >= operator
bool FeetInches::operator>=(const FeetInches &right) const
{
    bool status;

    if (feet >= right.feet)
        status = true;
    else if (feet == right.feet && inches >= right.inches)
        status = true;
    else
        status = false;

    return status;
}

// Overloaded <= operator
bool FeetInches::operator<=(const FeetInches &right) const
{
    return !(*this >= right);
}

// Overloaded == operator
bool FeetInches::operator==(const FeetInches &right) const
{
    bool status;

    if (feet == right.feet && inches == right.inches)
        status = true;
    else
        status = false;

    return status;
}

// Overloaded != operator
bool FeetInches::operator!=(const FeetInches &right) const
{
    return !(*this == right);
}

float FeetInches::toFeet() const
{
    return feet + (inches / 12.0f);
}

// Overloaded << operator
ostream &operator<<(ostream &out, const FeetInches &obj)
{
    out << "Feet = " << obj.feet << "\tInches = " << obj.inches << endl;

    return out;
}

// Overloaded >> operator
istream &operator>>(istream &in, FeetInches &obj)
{
    cout << "Enter Feet:\t";
    in >> obj.feet;

    cout << "Enter Inches:\t";
    in >> obj.inches;

    return in;
}