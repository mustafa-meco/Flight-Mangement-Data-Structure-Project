#pragma once
#include "EVENTS/EVENTS.h"



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

