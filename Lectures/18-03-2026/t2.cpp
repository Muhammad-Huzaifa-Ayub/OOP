#include <iostream>

using namespace std;

class Point{
		int x, y;
	public:
		Point(int x = 0, int y = 0){	this->x = x; this ->y = y;	}
		void show(){	cout << x << ' ' << y << "\n";				}
		void operator + (Point &p){
			
		}
		void operator + (int x){}
		void operator == (Point &p){}
		void operator /= (Point &p){}
};
int main(){
	Point p1(3, 4), p2(5, 1);
	p1.show();
	p2.show();
	p1 + p2;
	p1 == p2;
	p1 /= p2;
	p1 + 3;
	return 0;
}