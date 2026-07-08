#include <iostream>

using namespace std;

class Point{
		int x, y;
	public:
		Point(int x = 0, int y = 0){	this->x = x; this ->y = y;	}
		void show(){	cout << x << ' ' << y << "\n";				}
		//pre decrement operator
		Point& operator -- (){
			cout<<"pre decrement operator"<<endl;
			x--;
			y--;
			return *this;			
		}
		//post decrement operator
		Point operator -- (int){
			cout<<"post decrement operator"<<endl;
			Point temp = *this;
			x--;
			y--;
			return temp;			
		}
		operator double()
		{
			return double(x+y)+0.0;
		}
};
int main(){
	Point p1(3, 4), p2(5, 6);
	cout << "P1: " ; p1.show();
	cout << "P2: " ; p2.show();
	cout << "P1: " ; (--p1).show();
	cout << "P2: " ; (--p2).show();
	Point p3 = p2--;
	cout << "P2: " ; p2.show();
	cout << "P3: " ; p3.show();
	cout << "P2: " ; (p2--).show();
	double d=p1;
	cout<<"double "<<d<<endl;
	return 0;
}