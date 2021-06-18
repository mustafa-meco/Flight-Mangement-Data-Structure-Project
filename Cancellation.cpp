#include "Cancellation.h"

Cancellation::Cancellation(int T, int id) : EVENTS (T, id) //comment
{
	tp = X;
}

//int Cancellation::getIDcancel()
//{
//	return IDcancel;
//}
//
//int Cancellation::getTimeCancel()
//{
//	return TimeCancel; 
//}

EventT Cancellation::getEventT() const { return X; }