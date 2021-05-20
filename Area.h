#pragma once
#include "Lanes.h"
#include "LANElist.h"
class Area
{

private:
	int AreaNum;                 // index for each area
	static int NumOfAreas;       //Variable for number of areas
/*	static int** ArrOfAreas;*/     //two dimentional array for areas  
	int NumOfLanes;             // Variable for number of lanes
	//LANElist<Lanes>* lanesLIST; 
public:

	Area(int c);                //constructor
	int DisOfAreas(int);        // function to get the distance between the given area and the existing area
	int getNumLanes();          // getter for number of lanes
	int getAreasNum();         // getter for index of area
	//void InsertLanes(Lanes l);
};

Area::Area(int c)
{
	AreaNum = c;
	//lanesLIST = new LANElist<Lanes>[];               /////////////
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
//
//void Area::InsertLanes(Lanes l)
//{
//	lanesLIST->EnqueueLANES(l);
//}
