#pragma once

#include "Node.h"

template <typename T>
class PNode : public Node<T>
{
	double Priority;
public:
	PNode(const T & item, double _priority): Node<T>(item)
	{
		Priority = _priority;
	}
	double getPriority()
	{
		return Priority;
	}
};

template <typename T>
class PriorityQueue
{
	Node<T>* backPtr;
	Node<T>* frontPtr;
public:
	PriorityQueue();

	bool isEmpty() const;
	bool enqueue(const T& newEntry, double Priority);
	bool dequeue(T& frntEntry, double& Priority);
	bool peekFront(T& frntEntry, double& Priority)  const;

	//toArray function to be used ONLY when drawing the queue items
	const T* toArray(int& count);	//returns array of T (array of items)

	~PriorityQueue();
};
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: Queue()
The constructor of the Queue class.

*/

template <typename T>
PriorityQueue<T>::PriorityQueue()
{
	backPtr = nullptr;
	frontPtr = nullptr;

}
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: isEmpty
Sees whether this queue is empty.

Input: None.
Output: True if the queue is empty; otherwise false.
*/
template <typename T>
bool PriorityQueue<T>::isEmpty() const
{
	if (frontPtr == nullptr)
		return true;
	else
		return false;
}

/////////////////////////////////////////////////////////////////////////////////////////

/*Function:enqueue
Adds newEntry at the back of this queue.

Input: newEntry .
Output: True if the operation is successful; otherwise false.
*/

template <typename T>
bool PriorityQueue<T>::enqueue(const T& newEntry, double Priority)
{
	Node<T>* newPNodePtr = new PNode<T>(newEntry, Priority);
	// Insert the new node
	if (isEmpty())
		frontPtr = newPNodePtr; // The queue is empty
	else
	{
		Node<T>* P = frontPtr;
		if (static_cast<PNode<T>*>(newPNodePtr)->getPriority() > static_cast<PNode<T>*>(P)->getPriority())
		{
			frontPtr = newPNodePtr;
			frontPtr->setNext(P);
			return true;
		}
		//else
		while (P->getNext())
		{
			if (static_cast<PNode<T>*>(newPNodePtr)->getPriority() > static_cast<PNode<T>*>(P->getNext())->getPriority())
			{
				newPNodePtr->setNext(P->getNext());
				P->setNext(newPNodePtr);
				return true;
			}
			//else
			P = P->getNext();
		}
		backPtr->setNext(newPNodePtr); // The queue was not empty
	}
	backPtr = newPNodePtr; // New node is at back
	return true;
} // end enqueue


/////////////////////////////////////////////////////////////////////////////////////////////////////////

/*Function: dequeue
Removes the front of this queue. That is, removes the item that was added
earliest.

Input: None.
Output: True if the operation is successful; otherwise false.
*/

template <typename T>
bool PriorityQueue<T>::dequeue(T& frntEntry, double& Priority)
{
	if (isEmpty())
		return false;

	Node<T>* nodeToDeletePtr = frontPtr;
	PNode<T>* Pnode = static_cast<PNode<T>*>(frontPtr);
	frntEntry = frontPtr->getItem();
	Priority = Pnode->getPriority();
	frontPtr = frontPtr->getNext();
	// Queue is not empty; remove front
	if (nodeToDeletePtr == backPtr)	 // Special case: one node in queue
		backPtr = nullptr;

	// Free memory reserved by the dequeued node
	delete nodeToDeletePtr;


	return true;

}

/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: peekFront
gets the front of this queue. The operation does not modify the queue.

Input: None.
Output: The front of the queue.
return: flase if Queue is empty
*/
template <typename T>
bool PriorityQueue<T>::peekFront(T& frntEntry,double& Priority) const
{
	if (isEmpty())
		return false;

	PNode<T>* pnode = NULL;
	frntEntry = frontPtr->getItem();
	Priority = pnode->getPriority();
	return true;

}
///////////////////////////////////////////////////////////////////////////////////

template <typename T>
PriorityQueue<T>::~PriorityQueue()
{
}

/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: toArray
returns an array of "T"
Output: count: the length of the returned array (zero if Queue is empty)
returns: The array of T. (nullptr if Queue is empty)
*/

//IMPORTANT:
//toArray function to be used ONLY when drawing the queue items

template <typename T>
const T* PriorityQueue<T>::toArray(int& count)
{

	//IMPORTANT:
	//toArray function to be used ONLY when drawing the queue items

	count = 0;

	if (!frontPtr)
		return nullptr;
	//counting the no. of items in the Queue
	Node<T>* p = frontPtr;
	while (p)
	{
		count++;
		p = p->getNext();
	}


	T* Arr = new T[count];
	p = frontPtr;
	for (int i = 0; i < count;i++)
	{
		Arr[i] = p->getItem();
		p = p->getNext();
	}
	return Arr;
	//IMPORTANT:
	//toArray function to be used ONLY when drawing the queue items

}

