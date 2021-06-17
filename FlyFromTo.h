#pragma once
#include "EVENTS/EVENTS.h"
#include "Area.h"
class FlyFromTo :   public EVENTS
{
private:
	/*int IDFly;
	int TimeFly;*/
	//TnL Area;
	Lanes FromLane;               // The lane where the flight take off
	Lanes ToLane;                 // The lane where the flight will lane on 
public:
	FlyFromTo(int t, int id,Lanes from, Lanes to); 
	Lanes getFromLane();
	Lanes getToLane();
};

