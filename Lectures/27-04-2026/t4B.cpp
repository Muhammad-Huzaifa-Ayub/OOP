#include <iostream>

using namespace std;

class A{
	protected:
		A(){ cout << "Constructor of class A\n";}
	public:
		
};
class B: public A{
	public:
	//                                                                 added by me , use  " A obj; " to avoid error
};
int main(){
	A objA;
	B objB;
	return 0;
}