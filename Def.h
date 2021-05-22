#pragma once
#include "Scheduler.h"

enum Sp { Normal = 0, VIP = 1 };

enum EventT { B = 0, X = 1, P = 2 };

class TnL {
private:

public:
	Area* TA;
	Area* LA;
};

//struct Event {
//	int ID;
//	int TS;
//	int TA;
//	int LA;
//	Sp typ;
//	int Pass;
//};

