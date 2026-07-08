#include <iostream>

using namespace std;

class StaticArray {
		static int dir[4];              // USE :    "inline const static int dir[4] = {0};"   to declare inside class with the value "0".
	public:
		static void showDir(){
			cout << dir[0] << ' '  << dir[1] << ' '  << dir[2] << ' '  << dir[3] << '\n' ;
		}
};
int StaticArray::dir[] = {0,1,2,3};
int main(){
	StaticArray::showDir();
	return 0;
}
