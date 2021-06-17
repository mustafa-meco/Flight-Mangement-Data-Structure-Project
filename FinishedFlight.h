#pragma once
#include "EVENTS/EVENTS.h"
#include "Area.h"
#include "Lanes.h"
class FinishedFlight : public EVENTS
{
private: 
	int TimeFinish;
	int IDfinish;
	int TimeServed;
	Lanes FinishedLane;
	Area FinishedArea;
public:
	FinishedFlight(int t, int id, int Tserve, Lanes *l);
	int getTimeServed();
	Lanes getFinishedLane();
};

