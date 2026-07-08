#include <iostream>

using namespace std;

class Static {
	int x;
	public:
		static void about(){
			cout << "** This is a class to check Static Member Function **\n";
			//x = 1;	// static member function can't access instance data member
		}
};
int main(){
	Static::about();
	return 0;
}
