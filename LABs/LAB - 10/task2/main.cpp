#include "TeamLeader.h"

int main()
{
    char Name[50] = "M.ALi";
    int No = 1011;
    int shift = 2;
    double PayPerHr = 300;
    double MonthlyBonus = 20000;
    int rth = 25;
    int ath = 12;

    TeamLeader worker(Name,No,shift,PayPerHr,MonthlyBonus,rth,ath);
    worker.display();

    return 0;
}