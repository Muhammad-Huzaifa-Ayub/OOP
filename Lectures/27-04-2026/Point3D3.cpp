#include <iostream>

using namespace std;

class Point{
	protected:
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
		friend ostream& operator << (ostream& out, const Point3D& p){
			out << p.x << ' ' << p.y << ' ' << p.z;
			return out;
		}
};
int main(){
	Point p(3, 5);
	cout << p.x ;//                            x is protected, and main() is not allowed access
	Point3D p1(2, 5, 1);
	cout << p1;
	return 0;
}