#pragma once
#include "Lanes.h"
//#include "Scheduler.h"
#include "LinkedQueue.h"
//#include "Def.h"
using namespace std;
//class Scheduler;
//class Lanes;



class Area {

private:
	int countVIP;                         //counter for the VIP lanes
	int countNORM;                        //counter for the normal lanes
	int AreaNum;					      // index for each area
	//static int NumOfAreas;			  //Variable for number of areas
/*	static int** ArrOfAreas;*/		      //two dimentional array for areas  
	int NumOfLanes;					      // Variable for number of lanes
	LinkedQueue<Lanes*>* lanesLIST;		  //list to store the lanes
public:

	Area(int c, int n);                         
	//int DisOfAreas(int);                      
	int getNumLanes();					        
	int getAreasNum();							
	void InsertLanes(Sp s, int, int, int);    
	void InsertLane(Lanes* L);                  
	Lanes* getVIPlane(int, int);                     
	Lanes* getNORMlane(int t, int);                    
	int getNumVIP();                             
	bool checkN(int t);                           
	bool checkV(int t);                          
};
//struct TnL {
//	Area* TA;
//	Area* LA;
//};