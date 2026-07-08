#include <iostream>

using namespace std;

class Static {
		static int x;
	public:
		static void about(){
			cout << "** This is a class to check Static Member Function **\n";
		}
		static int getX() {
			return x;
		}
};
int Static::x ;
int main(){
	Static::about();
	cout << Static::getX() << '\n';
	return 0;
}
