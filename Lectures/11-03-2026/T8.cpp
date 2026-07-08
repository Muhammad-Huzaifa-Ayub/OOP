#include <iostream>

using namespace std;

class Constant {
		const static int LIMIT = 10;      //  Not give Error , because of  "const" 
	public:
		static int getLIMIT() {
			return LIMIT;
		}
};

int main(){
	cout << "Limit: " << Constant::getLIMIT() << '\n';
	return 0;
}
