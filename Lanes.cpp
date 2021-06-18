#include "Lanes.h"

Lanes::Lanes(Sp typ, int MA, int MT) {        //Constructor intialize the members
	type = typ;
	
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
											// Checking if there is no action at this time
{
	
	if (WorkingQueue.isEmpty()) {
		WorkingQueue.enqueue(time1,double(time2));
		return true;
	}
	
	int tempT1;
	double tempT2;
	PriorityQueue<int> tempQ;
	while (WorkingQueue.dequeue(tempT1,tempT2)) {
		tempQ.enqueue(tempT1, tempT2);
		if ((time2 < tempT1 && time2 > tempT2) || (time1 <tempT1 && time1 > tempT2)) {
			while (tempQ.dequeue(tempT1, tempT2)) WorkingQueue.enqueue(tempT1, tempT2);
			return false;
		}
	}
	WorkingQueue.enqueue(time1,time2);
	return true;
}


 

 
void Lanes::served()                         //Calculating the number of the times for the aiplane to know-
											 //-the time of its maintanence 
{
	int tempT1;
	double tempT2;
	WorkingQueue.dequeue(tempT1,tempT2);
	int end =tempT1;
	if (VARaft++>=MainAft)
	{
		WorkingQueue.enqueue(end,double(end+MainTime));
		VARtime = 0;
	}
}

void Lanes::cancel(int time1, int time2) {  //To cancel the booked flight, lane and decreasing the time.
	int tempT1;
	double tempT2;
	PriorityQueue<int> tempQ;
	while (WorkingQueue.dequeue(tempT1, tempT2)) {
		tempQ.enqueue(tempT1, tempT2);
		if (time2 == tempT1 && time1 == tempT2) {
			tempQ.dequeue(tempT1, tempT2);
			while (tempQ.dequeue(tempT1, tempT2)) WorkingQueue.enqueue(tempT1, tempT2);
			break;
		}
	}
}
Lanes::Lanes() {

}