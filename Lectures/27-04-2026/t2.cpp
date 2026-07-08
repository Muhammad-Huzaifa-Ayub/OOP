#include <iostream>

using namespace std;

class A{
	public:
};
//B class is child class of A
class B: public A{
	public:
		void about(){
			cout << "I am class B child of class A\n";
		}
};
int main(){
	B objB;
	objB.about();
	return 0;
}