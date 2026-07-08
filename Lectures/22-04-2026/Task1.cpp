#include <iostream>
// #include <string>
using namespace std;
class Book{
    string title;
    string author;
public:
    //This need to be checked
    //Book(string title = "", string author = ""){
    Book(string title, string author){
        this -> title = title;
        this -> author = author;
    }
    void print(){
        cout<<"Title: "<<this->title<<", Author: "<<this->author<<'\n';
    }
};
class Library{
    Book *b;
    int curr;
public:
    Library(){
        b = nullptr;
        curr = 0;
    }
    ~Library(){
        delete [] b;
    }
    void addBook(const Book& b1){
        Book* temp = new Book [curr + 1];
        for(int i = 0; i < curr; i++)
            temp[i] = b[i];
        temp[curr++] = b1;
        delete [] b;
        b = temp;
    }
    void displayBooks(){
        cout<<"-----Library Books------\n";
        for(int i = 0; i < curr; i++)
            b[i].print();
    }
};
int main(){
    Library lib;
    lib.addBook(Book("C++ Basics","Bjarne"));
    lib.addBook(Book("Algorithms", "CLRS"));
    lib.displayBooks();
    return 0;
}   