#include "ASSIGNtoLane.h"

ASSIGNtoLane::ASSIGNtoLane(int T, int id, Lanes l, Area A): EVENTS(T, id)
{

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

Lanes ASSIGNtoLane::getAssignedLane1()
{
	return AssignedLane1;
}
Lanes ASSIGNtoLane::getAssignedLane2()
{
	return AssignedLane2;
}