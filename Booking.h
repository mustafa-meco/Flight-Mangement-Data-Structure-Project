#pragma once
#include "EVENTS/EVENTS.h"
#include "Scheduler.h"
using namespace std;


class Booking :
    public EVENTS
{
private:
    TnL As;
    Sp typ;
    int Pass;
public:
    Booking(/*int t,*/ int i, Area*, Area*, Sp, int);
    int calcOn(int t) const;
    int calcOf(int t) const;
    int getNpass() const;
    Sp getType() const;
    TnL getAreas() const;
};

