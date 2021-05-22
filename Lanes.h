#pragma once
#include <string>
#include "LANElist.h"
#include "Scheduler.h"
using namespace std;
class Lanes
{

	char Lane_Specialization;
	int Availability_Time;   //As the flight taxi becomes popular, more lanes will be added.A lane is available when it’s availability time is reached.
	int MainAft;			  //Each lane needs servicing after a number of flights.
	int MainTime;			//Each lane takes a service time to finish maintenance.
	int VARaft;             
	int VARtime;
	bool aval;               //booleanto check if the lanes available or not
	Sp type;                 //Variable to define the type of the lane if it is VIP or Normal


public:

	Lanes(Sp typ, int Avt, int MA, int MT);              //Constructor intialize the members
	bool check(int t);                                // Boolean function to check the Availability of the lane.
	Sp getType();                                        // getter for the type of the lane
	void Activate();                                     // function to activate the lane 
	bool Serving(int time1, int time2);                  // function to serve the lane (deactivate the lane during the serving time)
};


Lanes::Lanes(Sp typ, int Avt, int MA, int MT)   
{
	type = typ;
	Availability_Time = Avt;
	MainAft = MA;
	MainTime = MT;
	VARaft = 0;
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


Sp Lanes::getType()
{
	return type;
}

void Lanes::Activate()
{
	aval = true;
}

bool Lanes::Serving(int time1, int time2)
{
	if (check(time1))
	{
		VARaft++;
		aval = false;
		Availability_Time = time1 + time2;
		return true;
	}
	else
	{
		return false;
	}
}

bool Lanes::check(int t) {
	return Availability_Time < t;
}