#ifndef TeamLeader_H
#define TeamLeader_H

#include "ProductionWorker.h"

class TeamLeader : protected ProductionWorker {

    private : 

    double MonthlyBonus;
    int rth;
    int ath;

    public :

    TeamLeader();
    TeamLeader( const char* Name, int No, int shift, double PayPerHr, double MonthlyBonus, int rth, int ath );
    void setMonthlyBonus(double &MonthlyBonus);
    void setrth(int &rth);
    void setath(int &ath);
    double getMonthlyBonus()const;
    int getrth()const;
    int getath()const;
    void display()const;

};

#endif