#include <iostream>

using namespace std;

class A{
	public:
		A(int x){ cout << "Constructor of class A\n";}
};
class B: public A{
	public:
		B(int a, int b):A(a){ cout << "Constructor of class B\n";}//              When creating B, take value a and pass it to A’s constructor”
};
int main(){
	B objB(5, 1);
	return 0;
}