#include <iostream>
using namespace std;
class Base {
	virtual void method() { 
		cout << "from Base" << endl;
	}
public:
	virtual ~Base() { method(); }
	void baseMethod() { method(); }
};

class A : public Base {
	void method()
	{
		cout << "from A" << endl;
	}
public:
	~A() { method(); }
};
int main(void) {
	Base* base = new A;
	base->baseMethod();
	delete base;
	return 0;
}
