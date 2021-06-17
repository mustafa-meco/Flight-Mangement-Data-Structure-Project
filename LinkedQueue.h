#pragma once


#include "Node.h"
#include "QueueADT.h"

template <typename T>
class LinkedQueue:public QueueADT<T>    //Data Stucture a Queue impelmentation with linkedlist
{
private :
	Node<T>* backPtr;                   //Pointer for the element which will be equeued 
	Node<T>* frontPtr;                  // Pointer for the first elemet which will be equeued 
public : 
	LinkedQueue();	
	bool isEmpty() const ;              // function to check if there is any element in the list or not. 
	bool enqueue(const T& newEntry);    // Function to enqueue the elements in the array
	bool dequeue(T& frntEntry);         // Function to dequeue the last element from the array 
	bool peek(T& frntEntry)  const;	    // Function to print the first element on the list
	~LinkedQueue();                     // Destructor for the queue to remove all the elements and free the memory  
};

template <typename T>
LinkedQueue<T>::LinkedQueue()
{
	backPtr=nullptr;
	frontPtr=nullptr;

}

template <typename T>
bool LinkedQueue<T>::isEmpty() const
{
	return (frontPtr==nullptr);
}

template <typename T>
bool LinkedQueue<T>::enqueue( const T& newEntry)
{
	Node<T>* newNodePtr = new Node<T>(newEntry);

	if (isEmpty())	
		frontPtr = newNodePtr; 
	else
		backPtr->setNext(newNodePtr); 

	backPtr = newNodePtr; 
	return true ;
}


template <typename T>
bool LinkedQueue<T>:: dequeue(T& frntEntry)  
{
	if(isEmpty())
		return false;

	Node<T>* nodeToDeletePtr = frontPtr;
	frntEntry = frontPtr->getItem();
	frontPtr = frontPtr->getNext();

	if (nodeToDeletePtr == backPtr)	
		backPtr = nullptr ;	

	delete nodeToDeletePtr;

	return true;
}

template <typename T>
bool LinkedQueue<T>:: peek(T& frntEntry) const 
{
	if(isEmpty())
		return false;

	frntEntry = frontPtr->getItem();
	return true;

}

//template <typename T>
//LinkedQueue<T>::~LinkedQueue()
//{
//
//	cout<<"\nStarting LinkedQueue destructor...";
//	cout<<"\nFreeing all nodes in the queue...";
//
//	//Free all nodes in the queue
//	T temp;
//	while(dequeue(temp));
//	
//	cout<<"\n Is LinkedQueue Empty now?? ==> "<<boolalpha<<isEmpty();
//	cout<<"\nEnding LinkedQueue destructor..."<<endl;
//}

template <typename T>
LinkedQueue<T>::~LinkedQueue() {

}