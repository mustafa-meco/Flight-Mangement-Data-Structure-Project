#pragma once
class Area
{

private:
	int AreaNum;
	static int NumOfAreas;
	static int** ArrOfAreas;
	int NumOfLanes;
public:

	Area(int c);
	int DisOfAreas(int);
	int getNumLanes();

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