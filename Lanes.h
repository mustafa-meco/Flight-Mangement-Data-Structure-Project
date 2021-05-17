#pragma once
#include <string>
using namespace std;
class Lanes
{

	char Lane_Specialization;
	int Availability_Time;   //As the flight taxi becomes popular, more lanes will be added.A lane is available when it’s availability time is reached.
	int MainAft;   //Each lane needs servicing after a number of flights.
	int MainTime;    //Each lane takes a service time to finish maintenance.
	int VARaft;
	int VARtime;
	bool aval;


public:
	Lanes(/*int Lane_Area,*/ char specialization, int availability_time, int maintenance_after, int maintenance_time);
	~Lanes();
	bool check();
};
//no priority in the same type of lanes

bool Lanes::check()
{
	if (aval)
	{
		if (VARaft == MainAft)
		{
			aval = false;
			VARaft = 0;
		}
	}
	else 
	{
		if (VARtime== MainTime)
		{
			aval = true;
		}
		else
		{
			VARtime++;
		}
	}
}
