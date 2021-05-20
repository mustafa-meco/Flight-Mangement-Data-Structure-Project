#pragma once
#include "Area.h"
#include <iostream>
using namespace std;

template <typename T>
class AreasList
{
private:
	int numAreas;                   //variable for Number of Areas
	int** Dists;                    //two dimentional array of distances.
	T** Areas;                      //two dimentional array of Areas.
	int size;                          
public:
	AreasList(int);              //Constructor
	void InsertArea(T*);         //function to insert a new area in the array
 	Area* getArea(int);          // return an area
	void addDist(int a, int d);  // function to add area and its distance
	int getNumAreas() const;     // getter for number of arrays     
	~AreasList();

};

template <typename T>
AreasList<T>::AreasList(int n)
{
	numAreas = n;
	Areas = new T * [n];
	Dists = new int* [n];
	for (int i = 0; i < n; i++) Dists[i] = new int[n];
	size = 0;
}


Area* AreasList<Area>::getArea(int an) {
	return Areas[an - 1];
}

template<typename T>
int AreasList<T>::getNumAreas() const { return numAreas; }

//template<typename T>
void AreasList<Area>::InsertArea(Area* a) {
	Areas[size++] = a;
}


template <typename T>
void AreasList<T>::addDist(int a, int d) {
	
}



template <typename T>
AreasList<T>::~AreasList()
{
}