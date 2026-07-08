#include <iostream>

using namespace std;

class A{
		A(){ cout << "Constructor of class A\n";}   // compiler error due to private A();
	public:
};
class B: public A{
	public:
		
};
int main(){
	B objB;
	return 0;
}