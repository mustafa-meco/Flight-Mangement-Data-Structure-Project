#pragma once
#include "LinkedQueue.h"
#include "Lanes.h"
#include "Node.h"

template <typename T>
class LANElist
{
private:
	Node<T>* backPtr;
	Node<T>* frontPtr;
	int numOfLANES;                   //variable fo number of lanes 
	T* laneARR;           // array to  store lanes
	int counter=0;
public:
	LANElist(T l);                  // constructor
	bool EnqueueLANES(T lane);      // Function to insert the lanes   
	T DequeueLANES();               // function to get the lanes  
	bool isEmpty() const;
	bool checkALL();

};

template <typename T>
LANElist<T>::LANElist(T l)
{
	numOfLANES = l;  
	laneARR = new LinkedQueue[l];    
}

template <typename T>
bool LANElist<T>::EnqueueLANES(T lane)
{

	Node<T>* newNodePtr = new Node<T>(newEntry);

	if (isEmpty())  
		frontPtr = newNodePtr;
	else
		backPtr->setNext(newNodePtr);

	backPtr = newNodePtr;
	return true;
}

template <typename T>
T LANElist<T>::DequeueLANES()
{
	if (isEmpty())

		return false;

	Node<T>* nodeToDeletePtr = frontPtr;
	frntEntry = frontPtr->getItem();
	frontPtr = frontPtr->getNext(); 

	if (nodeToDeletePtr == backPtr)
		backPtr = nullptr;

	delete nodeToDeletePtr;

	return true;
} 

template <typename T>
bool LANElist<T>::isEmpty() const
{
	return (frontPtr == nullptr);
}

//template <typename T>
bool LANElist<Lanes>::checkALL()
{
	for (int i = 0; i < numOfLANES; i++)
	{
		if (laneARR->check())
		{
			return true;
			counter++;
		}

		if (counter == 0)
		{
			return false;
		}
	
	}
}
