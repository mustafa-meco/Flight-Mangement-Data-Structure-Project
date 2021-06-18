#pragma once
#ifndef _NODE
#define _NODE
template <typename T>
class Node
{
private:
	T item;           // A data item
	Node<T>* next;    // Pointer to next node
public :
	Node();                                // Default constuctor
	Node(const T & r_Item);	               //Constuctor to intilize the value 
	Node(const T & r_Item, Node<T>* nextNodePtr); //Comment 
	void setItem(const T & r_Item);        // Setter for the data.  
	void setNext(Node<T>* nextNodePtr);    //Setter for the next pointer
	T getItem() const ;                    //Getter for the data of the pointer
	Node<T>* getNext() const ;             //getter for the next pointer
}; // end Node
#endif

template < typename T>
Node<T>::Node() 
{
	next = nullptr;
} 

template < typename T>
Node<T>::Node( const T& r_Item)
{
	item = r_Item;
	next = NULL;
} 

template < typename T>
Node<T>::Node( const T& r_Item, Node<T>* nextNodePtr)
{
	item = r_Item;
	next = nextNodePtr;
}
template < typename T>
void Node<T>::setItem( const T& r_Item)
{
	item = r_Item;
} 

template < typename T>
void Node<T>::setNext(Node<T>* nextNodePtr)
{
	next = nextNodePtr;
} 

template < typename T>
T Node<T>::getItem() const
{
	return item;
} 

template < typename T>
Node<T>* Node<T>::getNext() const
{
	return next;
} 