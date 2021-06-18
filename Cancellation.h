#pragma once
#include"EVENTS/EVENTS.h"
using namespace std;

class EVENTS;
class Cancellation : public EVENTS
{
private:
	/*int IDcancel;
	int TimeCancel;*/

public:
	Cancellation(int T, int id);
	//int getIDcancel();
	//int getTimeCancel();
	EventT getEventT() const;
};

