#include "ProductionWorker.h"

ProductionWorker::ProductionWorker()
{
    Employee();
    this->shift = 0;
    this->PayPerHr = 0;
}
ProductionWorker::ProductionWorker(const char *Name, int No, int shift, double PayPerHr)
{
    setName(Name);
    setNo(No);
    this->shift = shift;
    this->PayPerHr = PayPerHr;
}
void ProductionWorker::setshift(int &shift)
{
    this->shift = shift;
}
int ProductionWorker::getshift() const
{
    return this->shift;
}
void ProductionWorker::setPayPerHr(double &PayPerHr)
{
    this->PayPerHr = PayPerHr;
}
double ProductionWorker::getPayPerHr() const
{
    return this->PayPerHr;
}
void ProductionWorker::display() const
{
    Employee::display();
    cout << "ProductionWorker shift      : " << shift << endl;
    cout << "ProductionWorker PayPerHour : " << PayPerHr << endl;
}