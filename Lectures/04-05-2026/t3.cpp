#include <iostream>

using namespace std;

class Printer{
	public:
		virtual void print()=0;//pure virtual function
};
class Inkjet : public Printer{
	public:
		void print(){ cout << "Inkjet Prining\n";	}//function override
};
int main(){
	Printer *p = new Inkjet;
	p -> print();
	return 0;
}