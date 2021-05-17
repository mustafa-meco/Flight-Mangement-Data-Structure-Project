#include <iostream>
#include <fstream>
#include <string>
#include "Flights.h"
#include "Area.h"
#include "AreasList.h"
using namespace std;

#pragma once
class Scheduler
{
private:
	int tkft; //take off time 
	int lndt; //landing time
	int pnt; //one passenger on time
	int pft; //one passenger off time
	AreasList<Area>* AreasL;

public:
	Scheduler();
	bool readFile(string );
};
