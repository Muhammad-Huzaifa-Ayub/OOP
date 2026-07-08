#include <iostream>

using namespace std;

class Person {
		const string dob;
	public:
		Person(string dob): dob(dob){			}
		void show() const{
			cout << "Date of Birth: " << dob << '\n';
		}
};

int main(){
	Person p1("03-01-2006");
	Person p2("04-02-2008");
	p1.show();
	p2.show();
	return 0;
}

/*Person(string dob) {
    this->dob = dob;              // This gives Error because dob is const.
}*/