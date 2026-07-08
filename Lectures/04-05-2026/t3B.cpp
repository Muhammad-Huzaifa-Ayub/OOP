#include <iostream>

using namespace std;

class Printer{
		virtual void print()=0;//pure virtual function
	public:
};
class Inkjet : public Printer{
		void print(){ cout << "Inkjet Prining\n";	}//function override
	public:
		void test(){
			print();
		}
};
int main(){
	Inkjet ij;
	Printer *p = &ij;
	//p -> print();
	ij.test();
	return 0;
}