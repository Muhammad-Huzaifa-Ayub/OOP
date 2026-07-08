#include <iostream>

using namespace std;

template <class t>
t divide(t a, t b){
	return  a / b;
}
int main(){
	cout << divide (3, 4) << '\n';
	cout << divide (3.0, 4) << '\n';
	return 0;
}