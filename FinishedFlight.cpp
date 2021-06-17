#include "FinishedFlight.h"

FinishedFlight::FinishedFlight(int t, int id, int Tserve, Lanes l): EVENTS(t, id)  //comment
{

	TimeServed = Tserve;
	FinishedLane = l;
//	FinishedArea = A;
}
int FinishedFlight::getTimeServed() //getter for the time which  the airplane takes to make the passengers get on the plane + taking off the lane. //comment
{
	return TimeServed;
}

Lanes FinishedFlight::getFinishedLane() // comment 
{
	return FinishedLane;
}