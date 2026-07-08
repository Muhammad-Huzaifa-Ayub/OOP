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
	Object *o1 = new Object;
	Object *o2 = new Object;;
	cout << "Object Count: " << Object::getCount() << '\n';
	Object o3(*o2);
	cout << "Object Count: " << Object::getCount() << '\n';
	delete o1;
	cout << "Object Count: " << Object::getCount() << '\n';
	delete o2;
	cout << "Object Count: " << Object::getCount() << '\n';
	return 0;
}
