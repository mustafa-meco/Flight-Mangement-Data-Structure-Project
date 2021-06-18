#include "Lanes.h"

Lanes::Lanes(Sp typ, int MA, int MT) {        //Constructor intialize the members
	type = typ;
	//Availability_Time = Avt;
	MainAft = MA;
	MainTime = MT;
	VARaft = 0;
	VARtime = 0;
	aval = false;
	
}

//bool Lanes::check(int time )
//{
//	if (time >Availability_Time)
//	{
//		if (VARaft == MainAft)
//		{
//			aval = false;
//			VARaft = 0;
//			Availability_Time = time + MainTime;
//		}
//	}
//	else 
//	{
//		if (VARtime== MainTime)
//		{
//			aval = true;
//			VARtime = 0;
//		}
//		/*else
//		{
//			VARtime++;
//		}*/
//	}
//
//	return aval;
//}


Sp Lanes::getType() const               // getter for the type of the lane
{
	return type;
}

void Lanes::Activate()                    // function to activate the lane
{
	aval = true;
}

bool Lanes::Serving(int time1, int time2)// function to serve the lane 
										   //(deactivate the lane during the serving time)
{											// Checking if there is no action at this time
	v<int>* workNode;
	if (WorkingQueue.isEmpty()) {
		workNode = new v<int>;
		*workNode = { time1,time2 };
		WorkingQueue.enqueue(*workNode);
		return true;
	}
	
	PriorityQueue<int> tempQ;
	while (WorkingQueue.dequeue(*workNode)) {
		tempQ.enqueue(*workNode);
		if ((time2 < workNode->value && time2 > workNode->priority) || (time1 < workNode->value && time1 > workNode->priority)) {
			while (tempQ.dequeue(*workNode)) WorkingQueue.enqueue(*workNode);
			return false;
		}
	}
	workNode = new v<int>;
	*workNode = { time1,time2 };
	WorkingQueue.enqueue(*workNode);
	return true;
}

bool Lanes::check(int t) {                   //Boolean function to check the Availability of the lane.
	return Availability_Time < t;
}
 
void Lanes::served()                         //Calculating the number of the times for the aiplane to know-
											 //-the time of its maintanence 
{
	v<int>* workNode = nullptr;
	WorkingQueue.dequeue(*workNode);
	int end =workNode->value;
	delete workNode;
	workNode = NULL;
	if (VARaft++>=MainAft)
	{
		workNode = new v<int>;
		*workNode = {end,end+MainTime};
		WorkingQueue.enqueue(*workNode);
		VARtime = 0;
	}
}

void Lanes::cancel(int time1, int time2) {    //To cancel the booked flight, lane and decreasing the time. 
	v<int>* workNode = nullptr;
	PriorityQueue<int> tempQ;
	while (WorkingQueue.dequeue(*workNode)) {
		tempQ.enqueue(*workNode);
		if (time2 == workNode->value && time1 == workNode->priority) {
			tempQ.dequeue(*workNode);
			delete workNode;
			workNode = NULL;
			while (tempQ.dequeue(*workNode)) WorkingQueue.enqueue(*workNode);
			break;
		}
	}
}