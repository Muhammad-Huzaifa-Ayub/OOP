#ifndef ProductionWorker_H
#define ProductionWorker_H

#include "Employee.h"

class ProductionWorker : protected Employee {

    private :

    int shift;
    double PayPerHr;

    public:

    ProductionWorker();
    ProductionWorker( const char* Name, int No, int shift, double PayPerHr );
    void setshift(int &shift);
    int getshift()const;
    void setPayPerHr(double &PayPerHr);
    double getPayPerHr()const;
    void display()const;

};

#endif