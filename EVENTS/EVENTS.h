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
	int TS;
	int ID;

protected:
	EventT tp;
public:
	EVENTS();
	EVENTS(int i, int);
	int getTS() const;
	int getID() const;
	virtual EventT getEventT() const;
};


