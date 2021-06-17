#include "Lanes.h"

Lanes::Lanes(Sp typ, int Avt, int MA, int MT) {
	type = typ;
	Availability_Time = Avt;
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


Sp Lanes::getType() const
{
	return type;
}

void Lanes::Activate()
{
	aval = true;
}

bool Lanes::Serving(int time1, int time2)
{
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

bool Lanes::check(int t) {
	return Availability_Time < t;
}

void Lanes::served()
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

void Lanes::cancel(int time1, int time2) {
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