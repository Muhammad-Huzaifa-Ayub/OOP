#include "TeamLeader.h"

TeamLeader::TeamLeader()
{
    ProductionWorker();
    this->MonthlyBonus = 0;
    this->rth = 0;
    this->ath = 0;
}
TeamLeader::TeamLeader(const char *Name, int No, int shift, double PayPerHr, double MonthlyBonus, int rth, int ath)
{
    setName(Name);
    setNo(No);
    setshift(shift);
    setPayPerHr(PayPerHr);
    this->MonthlyBonus = MonthlyBonus;
    this->rth = rth;
    this->ath = ath;
}
void TeamLeader::setMonthlyBonus(double &MonthlyBonus)
{
    this->MonthlyBonus = MonthlyBonus;
}
void TeamLeader::setrth(int &rth)
{
    this->rth = rth;
}
void TeamLeader::setath(int &ath)
{
    this->ath = ath;
}
double TeamLeader::getMonthlyBonus() const
{
    return this->MonthlyBonus;
}
int TeamLeader::getrth() const
{
    return this->rth;
}
int TeamLeader::getath() const
{
    return this->ath;
}
void TeamLeader::display() const
{
    ProductionWorker::display();
    cout << "TeamLeader MonthlyBouns : " << MonthlyBonus << endl;
    cout << "TeamLeader Required Training Hours : " << rth << endl;
    cout << "TeamLeader Attended Training Hours : " << ath << endl;
}