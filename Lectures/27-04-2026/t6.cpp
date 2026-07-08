#include <iostream>

using namespace std;

class A{
	public:
		A(int x){ cout << "Constructor of class A\n";}
};
class B: public A{
};
int main(){
	B objB;
	return 0;
}