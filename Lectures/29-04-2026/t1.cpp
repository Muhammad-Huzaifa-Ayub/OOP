#include <iostream>

using namespace std;

class Animal{
	bool alive;
	string species;
public:
	Animal(string species){
		alive = true;
		this -> species = species;
	}
	void eat() const{	cout << "Eat\n";		}
}; 
class Dog: public Animal{
	string breed;
public:
	Dog(string breed, string species):Animal(species){
		this->breed = breed;
	}
	void bark() const{	cout << "Bark\n";	}	
};
class Cat: public Animal{
	string furColor;
public:
	Cat(string furColor, string species):Animal(species){
		this->furColor = furColor;
	}
	void meow() const{	cout << "Meow\n";	}	
};
int main(){
	Dog d("Germen Shefered", "Dog");
	Cat c("Persian", "Cat");
	d.bark();
	c.meow();
	return 0;
}