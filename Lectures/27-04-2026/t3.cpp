#include <iostream>

using namespace std;

class A{
	public:
		void aboutA(){
			cout << "I am class A\n";
		}
};
//B class is child class of A
class B: public A{
	public:
		void aboutB(){
			cout << "I am class B child of class A\n";
		}
};
int main(){
	B objB;
	objB.aboutA();
	objB.aboutB();
	return 0;
}