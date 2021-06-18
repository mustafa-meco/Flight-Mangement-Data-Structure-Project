#pragma once
#include "EVENTS/EVENTS.h"
#include "Area.h"
class AddLane :
    public EVENTS
{
private:
    int MainAft;	//		  //Each lane needs servicing after a number of flights.
    int MainTime;
    Sp type;
    Area* Ar;
public:
    AddLane(int T, Area* ar,Sp type, int MA, int MT);
    int getMAf() const;
    int getMT() const;
    Sp getTY() const;
    EventT getEventT() const;
    Area* getArea() const;
};

