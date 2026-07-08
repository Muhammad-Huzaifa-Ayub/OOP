#include <iostream>

using namespace std;

template <class t>
t divide(t a, t b){
	return  a / b;
}
template <class t1, class t2>
t1 divide(t1 a, t2 b){
	return  a / b;
}
int main(){
	cout << divide (3, 4) << '\n';
	cout << divide (3.0, 4) << '\n';
	return 0;
}