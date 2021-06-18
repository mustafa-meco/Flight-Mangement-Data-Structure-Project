#include "Promotion.h"

Promotion::Promotion(int t, int i) : EVENTS(t, i)
{
	tp = P;
}

EventT Promotion::getEventT() const { return P; }