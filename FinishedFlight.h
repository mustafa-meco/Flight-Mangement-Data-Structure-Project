#pragma once
#include "EVENTS/EVENTS.h"
#include "Area.h"
#include "Lanes.h"
class FinishedFlight : public EVENTS
{
private: 
	int TimeFinish;  // Time which the plane will take from the lane to until taking off //comment
	int IDfinish;    // The id of the airplane which is finished.  
	int TimeServed;  // time which the airplane takes to make the passengers get on the plane + taking off the lane. //comment
	Lanes FinishedLane; //comment 
	Area FinishedArea;  //comment 
public:
	FinishedFlight(int t, int id, int Tserve, Lanes *l);
	int getTimeServed();
	Lanes getFinishedLane();
};

