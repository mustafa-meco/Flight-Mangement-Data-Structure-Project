//#ifndef _LINKEDLIST
//#define _LINKEDLIST
//
//#include "Scheduler.h"
//#include "Node.h"
//
//template <typename T>
//class LinkedList
//{
//private:
//	Node<T> *Head;	//Pointer to the head of the list
//		//You can add tail pointer too (depending on your problem)
//	int count;	//Number of nodes in the list
//public:
//	LinkedList();
//	~LinkedList();
//	void PrintList();	//prints all items in the list
//	void InsertBeg(T data);	//inserts a new node at list head
//	void DeleteAll();	//Deletes all nodes in the list
//
//	
//	void InsertEnd(T data);	
//	bool Find(T Key);
//	int CountOccurance(T value);
//	void DeleteFirst();
//	void DeleteLast();
//	
//	
//};
//
//#endif	
//
//template <typename T>
//LinkedList<T>::LinkedList()
//{
//	count = 0;
//	Head = NULL;
//}
//
//template <typename T>
//LinkedList<T>::~LinkedList()
//{
//	DeleteAll();
//}
//
//
//void LinkedList::PrintList()
//{
//	cout << "\nList has " << count << " nodes";
//	cout << "\nprinting list contents:\n\n";
//	Node* p = Head;
//
//	while (p != NULL)
//	{
//		cout << "[ " << p->getItem() << " ]";
//		cout << "--->";
//		p = p->getNext();
//	}
//	cout << "*\n";
//}
//
//
//void LinkedList::InsertBeg(int data)
//{
//	Node* R = new Node(data);
//	R->setNext(Head);
//	Head = R;
//	count++;
//
//}
//
//
//void LinkedList::DeleteAll()
//{
//	Node* P = Head;
//	while (Head != NULL)
//	{
//		P = Head->getNext();
//		delete Head;
//		Head = P;
//	}
//	count = 0;
//}
//
//bool LinkedList::Find(int Key) {
//	Node* n = Head;
//	while (n) {
//
//		if (n->getItem() == Key)
//			return true;
//		n = n->getNext();
//	}
//	return false;
//}
//
//int LinkedList::CountOccurance(int value) {
//	Node* n = Head;
//	int oc = 0;
//	while (n) {
//
//		if (n->getItem() == value)
//			oc++;
//		n = n->getNext();
//	}
//	return oc;
//}
//
//void LinkedList::DeleteFirst() {
//	Node* n = Head->getNext();
//	delete Head;
//	Head = n;
//	count--;
//}
//
//void LinkedList::DeleteLast() {
//
//	Node* n = Head;
//	if (n && !(n->getNext())) {
//		this->DeleteAll();
//	}
//	else {
//		while (n->getNext()->getNext()) {
//			n = n->getNext();
//		}
//		delete n->getNext();
//		n->setNext(NULL);
//
//		count--;
//	}
//
//}
//
