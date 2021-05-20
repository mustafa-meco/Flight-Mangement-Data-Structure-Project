#pragma once
#include "Lanes.h"
#include "LANElist.h"
#include "Scheduler.h"
class Area
{

private:
	int countVIP;
	int countNORM;
	int AreaNum;                 // index for each area
	static int NumOfAreas;       //Variable for number of areas
/*	static int** ArrOfAreas;*/     //two dimentional array for areas  
	int NumOfLanes;             // Variable for number of lanes
	LANElist<Lanes>* lanesLIST; 
public:

	Area(int c, int n);                //constructor
	int DisOfAreas(int);        // function to get the distance between the given area and the existing area
	int getNumLanes();          // getter for number of lanes
	int getAreasNum();         // getter for index of area
	void InsertLanes(Sp type, int Avt, int MA, int MT);
	Lanes getVIPlane();
	Lanes getNORMlane();
	int getNumVIP();
	int getNumLanes();
};

Area::Area(int c, int n)
{
	AreaNum = c;
	lanesLIST = new LANElist<Lanes>(n);               /////////////
	NumOfAreas++;
}

// function insert lane +++ list of lanes
//int Area::DisOfAreas(int A)
//{
//	return ArrOfAreas[AreaNum][A];
//}

int Area::getNumLanes()
{
	return NumOfLanes;
}

int Area::getAreasNum()
{
	return AreaNum;
}

void Area::InsertLanes(Sp typ, int Avt, int MA, int MT)
{
	if (typ == VIP)
	{
		countVIP++;
	}

	if (typ == Normal)
	{
		countNORM++;
	}
	Lanes* L1 = new Lanes(typ, Avt, MA, MT);
	lanesLIST->EnqueueLANES(*L1);
	delete L1;
}

Lanes Area::getVIPlane()
{
//	Sp type;
// 	   
	//for (/*int i = 0; i < NumOfLanes; i++*/)   
	Lanes* temp = &lanesLIST->Dequeue();
	Lanes* l = temp;
	do
	{
		if (l->getType() == VIP)
		{
			return *l;
		}
		else
		{
			lanesLIST->EnqueueLANES(*l);
		}
		l = &lanesLIST->Dequeue();

	} while (l != temp);
		lanesLIST->EnqueueLANES(*l);

		
	
}

Lanes Area::getNORMlane()
{
	Lanes* temp = &lanesLIST->Dequeue();
	Lanes* l = temp;
	do
	{
		if (l->getType() == Normal)
		{
			return *l;
		}
		else
		{
			lanesLIST->EnqueueLANES(*l);
		}
		l = &lanesLIST->Dequeue();

	} while (l != temp);
	lanesLIST->EnqueueLANES(*l);
}

int Area::getNumVIP()
{
	return countVIP;
}

int Area::getNumLanes()
{
	return countNORM;
}


