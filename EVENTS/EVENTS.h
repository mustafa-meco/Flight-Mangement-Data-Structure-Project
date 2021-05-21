#pragma once
#include "../Scheduler.h"
using namespace std;

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

EVENTS::EVENTS(int i)
{
	//TS = t;
	ID = i;
	//tp = et;
}

int EVENTS::getID() const { return ID; }
//int EVENTS::getTS() const { return TS; }
EventT EVENTS::getEventT() const { return tp; }

