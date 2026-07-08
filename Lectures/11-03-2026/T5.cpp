#include <iostream>

using namespace std;

class Object {
		static int objCount;
	public:
		Object(){
			objCount++;
		}
		Object(const Object &obj){
			objCount++;
		}
		static int getCount(){
			return objCount;
		}
		~Object(){
			objCount--;
		}
};
int Object::objCount = 0;
int main(){
	Object o1, o2;
	cout << "Object Count: " << Object::getCount() << '\n';
	Object o3(o2);
	cout << "Object Count: " << Object::getCount() << '\n';
	return 0;
}
