#pragma once
#include "LinkedQueue.h"
#include "Lanes.h"
#include "Node.h"
#include "Scheduler.h"
using namespace std;

template <typename T>
class LANElist
{
private:
	Node<T>* backPtr;          //pointer at the rear of the queue        
	Node<T>* frontPtr;         //pointer at the front of the queue.
	int numOfLANES;            //variable fo number of lanes 
	//T** laneARR;             // array to  store lanes
	int size;

public:
	LANElist(int l);							//Constructor
	bool EnqueueLANES(T /***/newNodePtr);       // Function to insert the lanes   
	T Dequeue();							   // function to get the lanes  
	bool isEmpty() const;					   //Function to check if there is no lanes or not
	bool checkALL();                           // Function to check if all the lanes are available or not 

};

template <typename T>
LANElist<T>::LANElist(int l) 
{
	numOfLANES = l;   
	//laneARR = new T*[numOfLANES]; 
}

//template <typename T>
//bool LANElist<T>::EnqueueLANES(T * newEntry)
//{
//
//	Node<T>* newNodePtr = new Node<T>(*newEntry);
//
//	if (isEmpty())  
//		frontPtr = newNodePtr;
//	else
//		backPtr->setNext(newNodePtr);
//
//	backPtr = newNodePtr;
//	return true;
//}

template <typename T>
bool LANElist<T>::EnqueueLANES(T  newEntry)
{

	Node<T> newNodePtr = new Node<T>(newEntry);

	if (isEmpty())  
		frontPtr = newNodePtr;
	else
		backPtr->setNext(newNodePtr);

	backPtr = newNodePtr;
	return true;
}

//template <typename T>
Lanes LANElist<Lanes>::Dequeue()
{
	if (isEmpty())
		return;

	Node<Lanes>* nodeToDeletePtr = frontPtr;
	Lanes frntEntry = frontPtr->getItem();
	frontPtr = frontPtr->getNext(); 

	if (nodeToDeletePtr == backPtr)
		backPtr = nullptr;

	delete nodeToDeletePtr;

	return frntEntry;
} 

template <typename T>
bool LANElist<T>::isEmpty() const
{
	return (frontPtr == nullptr);
}

//template <typename T>
bool LANElist<Lanes>::checkALL()
{
	//int counter1=0;
	Node<Lanes>* N = frontPtr; 
	while (N)
	{ 
		if (N->getItem().check())         
		{
		//	counter1++;
			return true;
		}
		N = N->getNext();
		//if (//counter1 == 0)
		//{
		//	return false;
		//}
	}
	return false;
}
