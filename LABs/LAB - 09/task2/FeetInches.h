#include "iostream"

using namespace std;

class FeetInches
{
private:
    int feet;   // To hold a number of feet
    int inches; // To hold a number of inches

    // Private member function to simplify the values in feet and inches
    void simplify()
    {
        if (inches >= 12)
        {
            feet += (inches / 12);
            inches = inches % 12;
        }
        else if (inches < 0)
        {
            feet -= ((abs(inches) / 12) + 1);
            inches = 12 - (abs(inches) % 12);
        }
    }

public:
    // Constructor
    FeetInches(int f = 0, int i = 0);
   

    // Copy constructor
    FeetInches(const FeetInches &right);

    // Mutator function to set feet
    void setFeet(int f);
    

    // Mutator function to set inches
    void setInches(int i);
   

    // Accessor function to get feet
    int getFeet() const;
    

    // Accessor function to get inches
    int getInches() const;
    

    // Overloaded + operator
    FeetInches operator+(const FeetInches &right);

    // Overloaded - operator
    FeetInches operator-(const FeetInches &right);

    // Overloaded * operator
    FeetInches operator*(const FeetInches &right);

    // Overloaded prefix ++ operator
    FeetInches operator++();

    // Overloaded postfix ++ operator
    FeetInches operator++(int);

    // Overloaded prefix -- operator
    FeetInches operator--();

    // Overloaded postfix -- operator
    FeetInches operator--(int);

    // Overloaded > operator
    bool operator>(const FeetInches &right) const;

    // Overloaded < operator
    bool operator<(const FeetInches &right) const;

    // Overloaded >= operator
    bool operator>=(const FeetInches &right) const;

    // Overloaded <= operator
    bool operator<=(const FeetInches &right) const;

    // Overloaded == operator
    bool operator==(const FeetInches &right) const;

    // Overloaded != operator
    bool operator!=(const FeetInches &right) const;

    float toFeet() const;

    // Friend function to overload << operator for output
    friend ostream &operator<<(ostream &, const FeetInches &);

    // Friend function to overload >> operator for input
    friend istream &operator>>(istream &, FeetInches &);
};

// Overloaded << operator
ostream &operator<<(ostream &out, const FeetInches &obj);


// Overloaded >> operator
istream &operator>>(istream &in, FeetInches &obj);