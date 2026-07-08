#include <iostream>

using namespace std;

class Printer{
	public:
		virtual void print()=0;//pure virtual/ abstract function
};
int main(){
	Printer *p = new Printer; // Error 
	return 0;
}