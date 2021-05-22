#pragma once
#include "Lanes.h"


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
	//int DisOfAreas(int);         // function to get the distance between the given area and the existing area
	int getNumLanes();           // getter for number of lanes
	int getAreasNum();           // getter for index of area
	void InsertLanes(Sp type, int Avt, int MA, int MT);    //Function to store lanes and define its type  
	void InsertLanes1(Lanes* L);
	Lanes* getVIPlane(int);                                    // return VIP lane
	Lanes *getNORMlane(int t);                                   // return NORMAL lane  
	int getNumVIP();                                      // return the number of VIP Lanes 
	bool checkN(int t) ;
	bool checkV(int t) ;
};

