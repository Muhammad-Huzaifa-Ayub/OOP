#include<iostream>
#include<string>

using namespace std;

class Circle{
	
	private : 
	
	double radius;
	const double PI = 3.14159;
	
	public :
		
	Circle( )
	{
		radius = 0.0;
	}
	Circle ( double r )
	{
		radius = r;
	}
	void setRadius ( double r )
	{
		radius = r;
	}
	double getRadius ( ) const
	{
		return radius;
	}
	double getArea ( double r )
	{
		radius = r;
		return radius*radius*PI;
	}
	double getDiameter ( double r )
	{
		radius = r;
		double d = radius * 2;
		return d;
	}
	double getCircumference ( double r )
	{
		radius = r;
		return 2*radius*PI;
	}
};

int main()
{
	double r;
	cout << "Enter radius of cicle : ";
	cin >> r;
	Circle c1( r );
	
	cout << "Radius is = " << c1.getRadius() << endl;
	cout << "Area of circle is = " << c1.getArea(r) << endl;
	cout << "Diameter of circle is = " << c1.getDiameter(r) << endl;
	cout << "Circumference of circle is = " << c1.getCircumference(r) << endl;
	
	return 0;
}