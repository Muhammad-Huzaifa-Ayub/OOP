#include <iostream>

using namespace std;

class A{
	public:
		A(){ cout << "Constructor of class A\n";}
};
class B: public A{
	public:
};
int main(){
	B objB;
	return 0;
}