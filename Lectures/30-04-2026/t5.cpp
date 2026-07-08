#include <iostream>

using namespace std;

class Printer{
	public:
		virtual void print(){	cout << "Print\n";	}
};
class Inkjet : public Printer{
	public:
		void print(){	cout << "Inkjet Print\n";	}
};
class Bubblejet : public Printer{
	public:
		void print(){	cout << "BubbleJet Print\n"; Printer::print();	}
		void test(){	cout << "Test of Bubglejet\n";	}
};

int main(){
	Printer *p = new Inkjet;
	p -> print();
	p = new Bubblejet;
	p -> print();
	cout << endl;
	Bubblejet *b = (Bubblejet*)p;
	b -> test();
	cout << endl;
	b -> Printer::print(); 
	return 0;
}