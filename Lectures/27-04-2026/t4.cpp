#include <iostream>

using namespace std;

class A{
	public:
		A(){ cout << "Constructor of class A\n";}
		~A(){ cout << "Destructor of class A\n";}
};
class B: public A{
	public:
		B(){ cout << "Constructor of class B\n";}
		~B(){ cout << "Destructor of class B\n";}
};
int main(){
	B objB;
	return 0;
}