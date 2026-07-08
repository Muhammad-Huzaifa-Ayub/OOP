#include <iostream>

using namespace std;

class Point{
		int x, y;
	public:
		Point(int x, int y){
			this -> x = x;
			this -> y = y;
		}
		int getX() const{	return x;		}
		int getY() const{	return y;		}
};
class Point3D: public Point{
		int z;
	public:
		Point3D(int x, int y, int z):Point(x, y){
			this -> z = z;
		}
		int getZ() const{
			return z;
		}
};
int main(){
	Point3D p1(2, 5, 1);
	cout << p1.getX() << ' ' << p1.getY() << ' ' << p1.getZ();
	return 0;
}