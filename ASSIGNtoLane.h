#pragma once
//#include "EVENTS.h"
#include "Lanes.h"
#include "Area.h"
#include "EVENTS/EVENTS.h"
class ASSIGNtoLane : public EVENTS
{
private: 
	Lanes AssignedLane1;
	Lanes AssignedLane2;
	//int IDAssign;
	//int TimeAssign;
	//TnL AssignedArea; 
public:
	ASSIGNtoLane(int T, int id, Lanes l, Area A);
	Lanes getAssignedLane1() const;
	Lanes getAssignedLane2() const;
	//int getIDAssign();
	//TnL getAssignedArea();
	//int getTimeAssign();
};

