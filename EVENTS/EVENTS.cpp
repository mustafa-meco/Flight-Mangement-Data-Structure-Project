#include "EVENTS.h"

EVENTS::EVENTS(int i)
{
	TS = t;
	ID = i;
	//tp = et;
}

int EVENTS::getID() const { return ID; }
//int EVENTS::getTS() const { return TS; }
EventT EVENTS::getEventT() const { 
	return tp; 
}
