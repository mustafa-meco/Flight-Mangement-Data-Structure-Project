#pragma once
#include "Area.h"
#include <iostream>
using namespace std;

template <typename T>
class AreasList
{
private:
	int numAreas;
	int** Dists;
	T** Areas;
public:
	AreasList(int);
	void addDist(int a, int d);
	int getNumAreas() const;
	~AreasList();

};

template <typename T>
AreasList<T>::AreasList(int n)
{
	numAreas = n;
	Areas = new T * [n];
	Dists = new int* [n];
	for (int i = 0; i < n; i++) Dists[i] = new int[n];
}


template<typename T>
int AreasList<T>::getNumAreas() const { return numAreas; }

template <typename T>
void AreasList<T>::addDist(int a, int d) {

}



template <typename T>
AreasList<T>::~AreasList()
{
}