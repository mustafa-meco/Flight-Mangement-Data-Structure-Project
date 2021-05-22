#pragma once
#include "Lanes.h"
#include "LANElist.h"
#include "Scheduler.h"
class Area
{

private:
	int countVIP;                     //counter for the VIP lanes
	int countNORM;                    //counter for the normal lanes
	int AreaNum;					  // index for each area
	static int NumOfAreas;			  //Variable for number of areas
/*	static int** ArrOfAreas;*/		  //two dimentional array for areas  
	int NumOfLanes;					  // Variable for number of lanes
	LinkedQueue<Lanes>* lanesLIST;		  //list to store the lanes
public:

	Area(int c, int n);          //constructor
	int DisOfAreas(int);         // function to get the distance between the given area and the existing area
	int getNumLanes();           // getter for number of lanes
	int getAreasNum();           // getter for index of area
	void InsertLanes(Sp, int, int, int);    //Function to store lanes and define its type  
	void InsertLanes(Lanes L);
	Lanes* getVIPlane(int);                                    // return VIP lane
	Lanes *getNORMlane(int t);                                   // return NORMAL lane  
	int getNumVIP();                                       // return the number of VIP Lanes 
	int getNumLanes();                                     // return the number of Normal Lanes 
	bool check(int t) const;
};

Area::Area(int c, int n)
{
	AreaNum = c;
	NumOfLanes = n;
	lanesLIST = new LinkedQueue<Lanes>;               /////////////
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

void Area::InsertLanes(Sp type, int Avt, int MA, int MT)
{
	if (type == VIP)
	{
		countVIP++;
	}

	if (type == Normal)
	{
		countNORM++;
	}
	Lanes* L1 = new Lanes(type, Avt, MA, MT);
	lanesLIST->enqueue(*L1);
	delete L1;
}

void Area::InsertLanes(Lanes L) {
	lanesLIST->enqueue(L);
}

Lanes* Area::getVIPlane(int t)
{
//	Sp type;
// 	   
	//for (/*int i = 0; i < NumOfLanes; i++*/)   
	Lanes* temp;
	lanesLIST->dequeue(*temp);
	Lanes* l = temp;
	do
	{
		if (l->getType() == VIP && l->check())
		{
			countVIP++;
			return l;
		}
		else
		{
			lanesLIST->enqueue(*l);
		}
		lanesLIST->dequeue(*l);

	} while (l != temp);
	lanesLIST->enqueue(*l);
	return NULL;
	
}

Lanes* Area::getNORMlane(int t)
{
	Lanes* temp;
	lanesLIST->dequeue(*temp);
	Lanes* l = temp;
	do
	{
		if (l->getType() == Normal && l->check(t))
		{
			return l;
		}
		else
		{
			lanesLIST->enqueue(*l);
		}
		lanesLIST->dequeue(*l);

	} while (l != temp);
	lanesLIST->enqueue(*l);
	return NULL;
}

int Area::getNumVIP()
{
	return countVIP;
}

int Area::getNumLanes()
{
	return countNORM;
}


bool Area::check(int t) const {
	if (Avt)
}