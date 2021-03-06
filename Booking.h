#pragma once
//#include "Scheduler.h"
#include "EVENTS/EVENTS.h"
#include "Area.h"
using namespace std;

//class EVENTS;

class Booking :public EVENTS {
private:
    //TnL As;
    Area *TA;          //Depareture Area
    Area *LA;          //Landing Area
    Sp typ;            //Type of the flight or the lane
    int Pass;          //Number of passengers    
public:
    Booking(int t, int i, Area*, Area*, Sp, int); 
    int calcOn(int t) const; 
    int calcOf(int t) const; 
    int getNpass() const; 
    Sp getType() const;
    //TnL getAreas() const; 
    Area* getTA() const;
    Area* getLA() const;
    EventT getEventT() const;
};

