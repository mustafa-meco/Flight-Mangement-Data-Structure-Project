#pragma once
#include "QueueADT.h"

//#include "Scheduler.h"
#include"Flights.h"
template <typename T>
struct v {
	int priority = NULL;
	T value = NULL;
};

//class Flights;
class EVENTS;
template <typename T>
class PriorityQueue
{
private:
	int front;
	int rear;
	v<T>* Arr;
	int size;
public:
	PriorityQueue(int size = 50);
	bool isEmpty() const;
	bool enqueue(const v<T>& newEntry);
	bool dequeue(v<T>& frntEntry);
	bool isFull() const;
	bool peek(v<T>& frntEntry)  const;
};

template<typename T>
PriorityQueue<T>::PriorityQueue(int s) {
	front = -1;
	rear = -1;
	Arr = new v<T>[s];
	size = s;
}

//template<typename T>
//PriorityQueue<T>::~PriorityQueue() {
//	for (int i = front; i <= rear; i++) {
//		delete Arr[i];
//		Arr[i] = NULL;
//	}
//	delete[] Arr;
//	Arr = NULL;
//}

template<typename T>
bool PriorityQueue<T>::isEmpty() const {
	return front != -1;
}

template<typename T>
bool PriorityQueue<T>::isFull() const {
	return (rear == size - 1 && front == 0) || (front == rear + 1);
}

template<typename T>
bool PriorityQueue<T>::enqueue(const v<T>& newEntry) {
	//if ((rear == size - 1 && front == 0) || (front == rear + 1))
		//return false;
	if (isFull())
		return false;
	if (rear == size - 1) {
		rear = (rear + 1) % size - 1;
	}
	Arr[++rear] = newEntry;
	int i = 0; v<T>* n = &Arr[rear];
	while (n->priority < Arr[rear - i - 1].priority) {
		*n = Arr[rear - i];
		Arr[rear - i ] = Arr[rear -i -1];
		Arr[rear - i - 1] = *n;
		if (rear - i == front)
			break;
		i++;
	}
	if (front == -1)
		Arr[++front] = newEntry;
	return true;
}

template<typename T>
bool PriorityQueue<T>::dequeue(v<T>& frntEntry) {
	if (isEmpty())
		return false;
	if (front == rear) {
		frntEntry = Arr[front];
		front = -1; rear = -1;
	}
	else
		frntEntry = Arr[front++];
	
	if (front == size-1) {
		front = (front + 1) % size - 1;
	}
	return true;
	
}

template<typename T>
bool PriorityQueue<T>::peek(v<T>& frntEntry) const
{
	if (isEmpty())
		return false;

	frntEntry = Arr[front];
	return true;

}