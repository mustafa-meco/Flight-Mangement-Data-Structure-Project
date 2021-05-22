#pragma once
#include "../Scheduler.h"

class EVENTS
{
private:
	//int TS;
	int ID;
	
protected:
	EventT tp;
public:
	EVENTS(int i);
	//int getTS() const;
	int getID() const;
	EventT getEventT() const;
};


