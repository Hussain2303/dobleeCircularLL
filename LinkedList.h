#include"Node.h"
#include<iostream>
using namespace std;
template <typename t>
class LinkedList {
protected:
	Node<t>* head;
	LinkedList();
	virtual void insertAtHead(t) = 0;
	virtual void displayFromHead() = 0;
	virtual void insertAtTail(t) = 0;
	virtual void displayFromTail() = 0;
	virtual void insertSorted(t) = 0;
	virtual t deleteFromHead() = 0;
	virtual t deleteFromTail() = 0;
};
template <typename t>
LinkedList<t>::LinkedList() {
	head = nullptr;
}

