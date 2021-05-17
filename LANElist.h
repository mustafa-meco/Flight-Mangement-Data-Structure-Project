#pragma once
#include "LinkedQueue.h"

template <typename T>
class LANElist
{
private:

	T numOfLANES;                   //variable fo number of lanes 
	LinkedQueue* laneARR;           // array to  store lanes
public:
	LANElist(T l);                 // constructor
	void EnqueueLANES(T lane);      // Function to insert the lanes   
	T DequeueLANES();                  // function to get the lanes  
};

template <typename T>
LANElist<T>::LANElist(T l)
{
	numOfLANES = l;  
	laneARR = new LinkedQueue[l];    
}

template <typename T>
void LANElist<T>::EnqueueLANES(T lane)
{
	laneARR->enqueue(lane);
}

template <typename T>
T LANElist<T>::DequeueLANES()
{
	return laneARR->dequeue();
} 


