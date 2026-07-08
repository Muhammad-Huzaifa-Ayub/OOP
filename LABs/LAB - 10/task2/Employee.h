#ifndef Employee_H
#define Employee_H

#include<iostream>
#include<cstring>

using namespace std;

class Employee{

    private :

    char Name[50];
    int No;

    public :

    Employee();
    Employee( const char* Name, int No );
    void setName(const char* Name);
    const char* getName()const;
    void setNo(int &No);
    int getNo()const;
    void display()const;

};

#endif 