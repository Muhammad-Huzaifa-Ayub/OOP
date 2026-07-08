#include <iostream>

using namespace std;

class A{};
//B class is child class of A
class B: public A{
};
int main(){
	B objB;
	cout << "End of Program\n";
	return 0;
}