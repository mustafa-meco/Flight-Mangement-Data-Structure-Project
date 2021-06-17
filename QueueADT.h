#pragma once
#include <iostream>
using namespace std;

template<class T>
class QueueADT    //Abstract Data Type explains the operations which will be done not its implementation. 
{
public:
   virtual bool isEmpty() const = 0;
   virtual bool enqueue(const T& newEntry) = 0;
   virtual bool dequeue(T& FrontEntry) = 0;
   virtual bool peek(T& FrontEntry) const = 0;
   virtual ~QueueADT() { }
};
