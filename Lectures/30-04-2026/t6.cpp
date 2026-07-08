#include <iostream>

using namespace std;

class Shape{
	public:
		virtual void draw(){		}
};
class Circle : public Shape{
	public:
		void draw(){	cout << "Circle Draw\n";	}
};
class Triangle : public Shape{
	public:
		void draw(){	cout << "Triangle Draw\n"; 	}
};
class Rectangle : public Shape{
	public:
		void draw(){	cout << "Rectangle Draw\n";	}
};
int main(){
	Shape *s[10];
	int i, c ;
	for (i = 0 ; i < 10 ; i++){
		c = rand() % 3;
		if (c == 0)			s[i] = new Circle;
		else if (c == 1)	s[i] = new Triangle;
		else if (c == 2)	s[i] = new Rectangle;
		s[i] -> draw();
	}
	return 0;
}