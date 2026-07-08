#include <iostream>

using namespace std;

template <typename t>
t divide(t a, t b){
	return  a / b;
}
class A{
	public:
		A operator / (A &obj){
			A c;
			cout << "Khawamkhwa\n";
			return c;
		}
		friend ostream& operator << (ostream &out, A &obj){
			out << "Something\n";
			return out;
		}
};
int main(){
	cout << divide (3, 4) << '\n';
	cout << divide (3.0, 4.0) << '\n';
	A a1, a2;
	A res = divide (a1, a2);
	cout << res << '\n';
	return 0;
}