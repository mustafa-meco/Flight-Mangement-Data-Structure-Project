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

void Lanes::served()
{
	if (VARaft++>MainAft)
	{
		VARtime = 0;
	}
}