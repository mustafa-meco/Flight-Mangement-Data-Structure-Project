#include "ASSIGNtoLane.h"

ASSIGNtoLane::ASSIGNtoLane() 
{

}
ASSIGNtoLane::ASSIGNtoLane(int T, int id, Lanes l, Area A): EVENTS(T, id)
{
	AssignedLane1 = l;
	AssignedArea.TA = &A;
}
//Lanes ASSIGNtoLane::getLane0()
//{
//	return Lane0;
//}

//int ASSIGNtoLane::getIDAssign()
//{
//	return IDAssign;
//}

//TnL ASSIGNtoLane::getAssignedArea()
//{
//	return AssignedArea;
//}

Lanes ASSIGNtoLane::getAssignedLane1() const
{
	return AssignedLane1;
}
Lanes ASSIGNtoLane::getAssignedLane2() const
{
	return AssignedLane2;
}