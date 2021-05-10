#pragma once
class Area
{

private:
	int AreaNum;
	static int** ArrOfAreas;
	int NumOfLanes;
public:

	Area();
	int DisOfAreas(int);
	int getNumLanes();

};

Area::Area()
{
	AreaNum = 0;
}

int Area::DisOfAreas(int A)
{
	return ArrOfAreas[AreaNum][A];
}

int Area::getNumLanes()
{
	return NumOfLanes;
}