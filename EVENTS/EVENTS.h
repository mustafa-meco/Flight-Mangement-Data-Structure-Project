#pragma once
//#ifndef DEF_H
//#define DEF_H
////
//#endif // !1
//#include "..\Scheduler.h"
#include "..\Def.h"

using namespace std;
//class Scheduler;
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


