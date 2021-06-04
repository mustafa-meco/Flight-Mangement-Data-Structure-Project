#pragma once
#include "EVENTS/EVENTS.h"
#include "Area.h"
class FlyFromTo :   public EVENTS
{
private:
	/*int IDFly;
	int TimeFly;*/
	//TnL Area;
	Lanes FromLane; 
	Lanes ToLane;
public:
	FlyFromTo(int t, int id,Lanes from, Lanes to); 
	Lanes getFromLane();
	Lanes getToLane();
};

