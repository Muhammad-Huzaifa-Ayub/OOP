#include <iostream>

using namespace std;

class Printer{
	public:
		virtual void print()=0;//pure virtual function
};
class Inkjet : public Printer{
	public:
		void print(){	cout << "Inkjet Printer\n";	}
};
class Bubblejet : public Printer{
	public:
		void print(){	cout << "Bubblejet Printer\n";	}
};
void test(Printer* p){
	p->print();
}
int main(){
	Bubblejet bj;
	Inkjet ij;
	test(&bj);
	test(&ij);
	return 0;
}