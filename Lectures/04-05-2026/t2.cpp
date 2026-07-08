#include <iostream>

using namespace std;

class Printer{
	public:
		virtual void print()=0;//pure virtual function
};
class Inkjet : public Printer{
};
int main(){
	Printer *p = new Inkjet;
	return 0;
}