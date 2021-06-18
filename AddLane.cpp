#include "AddLane.h"


AddLane::AddLane(int Ts, Area* ar, Sp ty, int A, int T) : EVENTS(Ts,0)
{
	Ar = ar;
	type = ty;
	MainAft = A;
	MainTime = T;
	tp = AL;
}

Sp AddLane::getTY() const { return type; }
int AddLane::getMAf() const { return MainAft; }
int AddLane::getMT() const { return MainTime; }
EventT AddLane::getEventT() const { return AL; }
Area* AddLane::getArea() const { return Ar; }