#include <iostream>

using namespace std;

class Printer{
	public:
		void print(){	cout << "Print\n";	}
};
class Inkjet : public Printer{
	public:
		void print(){	cout << "Inkjet Print\n";	}
};
class Bubblejet : public Printer{
	public:
		void print(){	cout << "BubbleJet Print\n";	}
		void test(){	cout << "Test\n";	}
};

int main(){
	Printer *p = new Inkjet;
	p -> print();
	p = new Bubblejet;
	p -> print();
	
	return 0;
}