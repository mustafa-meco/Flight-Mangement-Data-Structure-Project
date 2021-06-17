#include "Lanes.h"

Lanes::Lanes(Sp typ, int Avt, int MA, int MT,int i) {        //Constructor intialize the members
	type = typ;
	Availability_Time = Avt;
	MainAft = MA;
	MainTime = MT;
	VARaft = 0;
	VARtime = 0;
	aval = false;
	ID = i;
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

bool Lanes::Serving(int time1, int time2) 
{                                          // function to serve the lane 
										   //(deactivate the lane during the serving time)
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

bool Lanes::check(int t) {                   //Boolean function to check the Availability of the lane.
	return Availability_Time < t;
}
 
void Lanes::served()                         //Comment
{
	if (VARaft++>MainAft)
	{
		VARtime = 0;
	}
}