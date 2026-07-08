#include <iostream>

using namespace std;

class C{
		int x;
	public:

	C(){	cout << "NP Constructor\n";		}

	C(int x){cout << "P Constructor\n";	this->x = x; }

	C(int x, int y){cout << "P2 Constructor\n";	
				this->x = x + y; }
		void show(){	cout << x << "\n";}
};
int main(){
	C c[10] = {1,2,{},4,5,6,7,{8,0}};
	c[2].show();
	c[7].show();
	return 0;
}