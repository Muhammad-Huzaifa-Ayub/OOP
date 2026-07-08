#include "ProductionWorker.h"

int main()
{
    char Name[50] = "M.ALi";
    int No = 1011;
    int shift = 2;
    double PayPerHr = 300;
    ProductionWorker worker(Name,No,shift,PayPerHr);
    worker.display();

    return 0;
}