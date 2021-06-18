#include "Area.h"

Area::Area(int c, int n)               //Constructor to intialize the area number and the number of lanes.
{
	AreaNum = c;
	NumOfLanes = n;
	lanesLIST = new LinkedQueue<Lanes*>;               
	//NumOfAreas++;
}

// function insert lane +++ list of lanes
//int Area::DisOfAreas(int A)
//{
//	return ArrOfAreas[AreaNum][A];
//}

int Area::getNumLanes()                     // return the number of lanes 
{
	return NumOfLanes;
}

int Area::getAreasNum()                     // getter for index of area
{
	return AreaNum;
}

void Area::InsertLanes(Sp type, int MA, int MT) //Function to store lanes and define its type
{
	if (type == VIP)
	{
		countVIP++;
	}

	if (type == Normal)
	{
		countNORM++;
	}

	if (type==Cargo)
	{
		countCargo++;
	}
	Lanes* L1 = new Lanes(type, MA, MT);
	lanesLIST->enqueue(L1);
	delete L1;
}

void Area::InsertLane(Lanes* L) { //Function to insert lane in the laneList  // comment
	lanesLIST->enqueue(L);
}

Lanes* Area::getVIPlane(int t1, int t2)   //Getter for the VIP lanes from LanesList.
{
	//	Sp type;
	// 	   
		//for (/*int i = 0; i < NumOfLanes; i++*/)   
	Lanes* temp = nullptr;
	lanesLIST->dequeue(temp);
	Lanes* l = temp;
	do
	{
		if (l->getType() == VIP && l->Serving(t1,t2))
		{
			countVIP++;
			return l;
		}
		else
		{
			lanesLIST->enqueue(l);
		}
		lanesLIST->dequeue(l);

	} while (l != temp);
	lanesLIST->enqueue(l);
	return NULL;

}

Lanes* Area::getNORMlane(int t1,int t2)  //Getter for the normal lanes from LanesList
{
	Lanes* temp = nullptr;
	lanesLIST->dequeue(temp);
	Lanes* l = temp;
	do
	{
		if (l->getType() == Normal && l->Serving(t1,t2))
		{
			return l;
		}
		else
		{
			lanesLIST->enqueue(l);
		}
		lanesLIST->dequeue(l);

	} while (l != temp);
	lanesLIST->enqueue(l);
	return NULL;
}

int Area::getNumVIP()     // return the number of VIP Lanes 
{
	return countVIP;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
Lanes* Area::getCargolane(int t1, int t2)  //Getter for the Cargo lanes from LanesList
{
	Lanes* temp = nullptr;
	lanesLIST->dequeue(temp);
	Lanes* l = temp;
	do
	{
		if (l->getType() == Cargo && l->Serving(t1, t2))
		{
			countCargo++;
			return l;
		}
		else
		{
			lanesLIST->enqueue(l);
		}
		lanesLIST->dequeue(l);

	} while (l != temp);
	lanesLIST->enqueue(l);
	return NULL;
}

int Area::getNumCargo()   // return the number of Cargo Lanes 
{
	return countCargo;
}


bool Area::checkC(int t)
{

}

bool Area::checkEG(int t)
{

}

//bool Area::checkN(int t) {
//	Lanes* l = this->getNORMlane(t);
//	if (l)
//		this->InsertLane(l);
//	return l;
//}
//
//bool Area::checkV(int t) {
//	Lanes* l = this->getVIPlane(t);
//	if (l)
//		this->InsertLane(l);
//	return l;
//}