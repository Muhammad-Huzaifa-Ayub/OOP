#include <iostream>

using namespace std;

class Point{
		int x, y;
	public:
		Point(int x = 0, int y = 0){	this->x = x; this ->y = y;	}
		void show(){	cout << x << ' ' << y << "\n";				}
		Point operator += (Point &p){
			x = x + p.x;
			y = y + p.y;
			return *this;			
		}
		bool operator == (Point &p){
			return x == p.x && y == p.y;
		}
};
int main(){
	Point p1(3, 4), p2(5, 1);
	p1.show();
	p2.show();
	(p1 += p2).show();
	return 0;
}