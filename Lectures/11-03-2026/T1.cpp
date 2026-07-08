#include <iostream>

using namespace std;

class Static {
	public:
		static void about(){
			cout << "** This is a class to check Static Member Function **\n";
		}
};
int main(){
	Static::about();
	return 0;
}
