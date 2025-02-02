#include"Node.h"
#include<iostream>
using namespace std;
class LinkedList {
protected:
	Node* head;
	LinkedList();
	virtual void insertAtHead(int) = 0;
	virtual void displayFromHead() = 0;
	virtual void insertAtTail(int) = 0;
	virtual void displayFromTail() = 0;
	virtual void insertSorted(int) = 0;
	virtual int deleteFromHead() = 0;
	virtual int deleteFromTail() = 0;
};
LinkedList::LinkedList() {
	head = nullptr;
}

