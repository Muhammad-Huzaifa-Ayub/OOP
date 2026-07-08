#include <iostream>

using namespace std;

class A{
	public:
		A(int x){ cout << "Constructor of class A\n";}
};
class B: public A{
	public:
		B():A(5){ cout << "Constructor of class B\n";} //                 You are explicitly telling the compiler: “Before constructing B, call constructor of A with value 5”
};
int main(){
	B objB;
	return 0;
}