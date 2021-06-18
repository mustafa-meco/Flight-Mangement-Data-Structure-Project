#pragma once
#include "EVENTS/EVENTS.h"
#include "Area.h"
#include "Lanes.h"
class FinishedFlight : public EVENTS
{
private: 
	int TimeFinish;  // The time when the all passengers are out 
	int IDfinish;    // The id of the airplane which is finished.  
	int TimeServed;  // Time which the airplane takes to make the passengers get on the plane + taking off the lane. 
	Lanes FinishedLane; //The lane where the all passengers will be out 
	Area FinishedArea;  //The area which contains the previous lane
public:
	FinishedFlight(int t, int id, int Tserve, Lanes *l);  
	int getTimeServed();
	Lanes getFinishedLane();
};

