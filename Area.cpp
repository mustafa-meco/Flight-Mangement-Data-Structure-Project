#include "Area.h"

Area::Area(int c, int n) 
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

int Area::getNumLanes() // return the number of lanes 
{
	return NumOfLanes;
}

int Area::getAreasNum()                     // getter for index of area
{
	return AreaNum;
}

void Area::InsertLanes(Sp type, int Avt, int MA, int MT,int i) //Function to store lanes and define its type
{
	if (type == VIP)
	{
		countVIP++;
	}

	if (type == Normal)
	{
		countNORM++;
	}
	Lanes* L1 = new Lanes(type, Avt, MA, MT,i);
	lanesLIST->enqueue(L1);
	delete L1;
}

void Area::InsertLane(Lanes* L) { //Function to insert lane in the laneList  // comment
	lanesLIST->enqueue(L);
}

Lanes* Area::getVIPlane(int t) // return VIP lane // comment
{
	//	Sp type;
	// 	   
		//for (/*int i = 0; i < NumOfLanes; i++*/)   
	Lanes* temp = nullptr;
	lanesLIST->dequeue(temp);
	Lanes* l = temp;
	do
	{
		if (l->getType() == VIP && l->check(t))
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

Lanes* Area::getNORMlane(int t)                        // return NORMAL lane   // comment
{
	Lanes* temp = nullptr;
	lanesLIST->dequeue(temp);
	Lanes* l = temp;
	do
	{
		if (l->getType() == Normal && l->check(t))
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


bool Area::checkN(int t) {     // Function to check if the lane is normal or not
	Lanes* l = this->getNORMlane(t);
	if (l)
		this->InsertLane(l);
	return l;
}
 
bool Area::checkV(int t) { // Function to check if the lane is VIP or not 
	Lanes* l = this->getVIPlane(t);
	if (l)
		this->InsertLane(l);
	return l;
}


