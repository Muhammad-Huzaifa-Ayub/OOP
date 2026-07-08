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
	Animal(string species, bool alive){
		this->alive = alive;
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
	Dog(string breed, string species, bool alive):Animal(species, alive){
		this->breed = breed;
	}
	void eat() const{ cout << "Eat Meat\n";	}
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
	Animal a("xyz");
	a.eat();
	Dog d("Germen Shefered", "Dog");
	Cat c("Persian", "Cat");
	d.bark();
	d.eat();
	c.meow();
	return 0;
}