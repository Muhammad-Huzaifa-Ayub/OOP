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
};
int main(){
	Point p1(3, 4), p2(5, 1);
	p1.show();
	p2.show();
	Point p3 = p1 + p2;
	p3.show();
	(p1 + p2 + p3).show();
	return 0;
}