#include <iostream>

using namespace std;

class Point{
		int x, y;
	public:
		Point(int x = 0, int y = 0){	this->x = x; this ->y = y;	}
		void show(){	cout << x << ' ' << y << "\n";				}
		Point operator + (Point &p){
			Point temp;
			temp.x = x + p.x;
			temp.y = y + p.y;
			return temp;			
		}
		bool operator == (Point &p){
			return x == p.x && y == p.y;
		}
};
int main(){
	Point p1(3, 4), p2(5, 1);
	p1.show();
	p2.show();
	Point p3 = p1;
	if (p1 == p2)	cout << "P1 & P2 are same\n";
	else			cout << "P1 & P2 are different\n";
	if (p1 == p3)	cout << "P1 & P3 are same\n";
	else			cout << "P1 & P3 are different\n";
	return 0;
}