#pragma once
class Area
{

private:
	int AreaNum;                 // index for each area
	static int NumOfAreas;       //Variable for number of areas
	static int** ArrOfAreas;     //two dimentional array for areas  
	int NumOfLanes;             // Variable for number of lanes
public:

	Area(int c);                //constructor
	int DisOfAreas(int);        // function to get the distance between the given area and the existing area
	int getNumLanes();          // getter for number of lanes
	int getAreasNum();         // getter for index of area

};

Area::Area(int c)
{
	AreaNum = c;
	NumOfAreas++;
}

int Area::DisOfAreas(int A)
{
	return ArrOfAreas[AreaNum][A];
}

int Area::getNumLanes()
{
	return NumOfLanes;
}

int Area::getAreasNum()
{
	return AreaNum;
}