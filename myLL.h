#include"LinkedList.h"
class myLL :public LinkedList {
public:
	void insertAtHead(int);
	void displayFromHead();
	void insertAtTail(int);
	void displayFromTail();
	int deleteFromHead();
	int maxElement();
	void Factorial();
	int sumOfLL();
	void insertSorted(int);
	int deleteFromTail();
	void deleteEvenNodes();
	int findSecondMax();
};
int myLL::findSecondMax() {
	if (!head || head->next == head) {
		return -1;
	}
	int maxval = INT_MIN;
	int secMaxVal = INT_MIN;
	Node* temp = head;
	do {
		if (temp->data > maxval) {
			secMaxVal = maxval;
			maxval = temp->data;
		}
		else if (temp->data > secMaxVal && temp->data != maxval) {
			secMaxVal = temp->data;
		}
		temp = temp->next;
	} while (temp != head);
	return secMaxVal;
}
void myLL::deleteEvenNodes() {
	if (!head) {
		return;
	}
	Node* temp = head;
	do {
		Node* nextnode = temp->next;
		if (temp->data % 2 == 0) {
			if (temp->next == temp) {
				delete temp;
				head = nullptr;
				return;
			}
			else {
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				if (temp == head) {
					head = temp->next;
				}
				delete temp;
			}
		}
		temp = nextnode;
	} while (temp != head);
}
void myLL::insertSorted(int value)
{
	if (head == nullptr)
	{
		Node* nn = new Node;
		nn->data = value;
		nn->next = nn;
		nn->prev = nn;
		head = nn;
	}
	else if (value <= head->data)
	{
		insertAtHead(value);
	}
	else if (value >= head->prev->data)
	{
		insertAtTail(value);
	}
	else {
		Node* nn = new Node;
		nn->data = value;
		Node* t = head;
		while (1)
		{
			if (value>=t->data &&  value<=t->next->data)
			{
				nn->prev = t;
				nn->next = t->next;
				t->next = nn;
				nn->next->prev = nn;
				break;
			}
			t = t->next;
		}

	}
}
int myLL::deleteFromTail()
{
	if (head == nullptr)
	{
		return NULL;
	}
	else if (head == head->next) {
		int returningValue = head->data;
		delete head;
		head = nullptr;
		return returningValue;
	}
	else {
		int returningValue = head->prev->data;
		Node* t = head->prev->prev;
		delete head->prev;
		t->next = head;
		head->prev = t;
		return returningValue;
	}
}
int myLL::deleteFromHead()
{
	if (head == nullptr)
	{
		return NULL;
	}
	else if(head==head->next){
		int returningValue = head->data;
		delete head;
		head = nullptr;
		return returningValue;
	}
	else {
		int returningValue = head->data;
		Node* t = head->prev;
		head = head->next;
		delete head->prev;
		t->next = head;
		head->prev = t;
		return returningValue;
	}
}
int myLL::sumOfLL()
{
	Node* t = head;
	int sum = 0;
	do {
		sum = sum + t->data;
		t = t->next;
	} while (t != head);
	return sum;
}
void myLL::Factorial()
{
	Node* t = head;
	do {
	long long fact = 1;
		for (int i = t->data;i > 0;i--)
		{
			fact = fact * i;
		}
		cout <<"Factorial of "<<t->data<<"is"<<":"<< fact << " " << endl;
		t = t->next;
	} while (t != head);
}
int myLL::maxElement() {
	Node* t = head;
	int max = 0;
	do {
		if (t->data > max)
		{
			max = t->data;
		}
		t = t->next;
	} while (t != head);
	return max;
}
void myLL::insertAtHead(int value) {
	Node* nn = new Node;
	nn->data = value;
	if (head == nullptr)
	{
		nn->next = nn;
		nn->prev = nn;
		head = nn;
	}
	else {
		Node* t = head->prev;
		head->prev = nn;
		nn->prev = t;
		nn->next = head;
		t->next = nn;
		head = nn;

	}
}
void myLL::displayFromHead() {
	Node* t = head;
	do {
		cout << t->data << endl;
		t = t->next;
	} while (t != head);
}
void myLL::insertAtTail(int value) {
	Node* nn = new Node;
		nn->data = value;
	if (head == nullptr)
	{
		nn->next = nn;
		nn->prev = nn;
		head = nn;
	}
	else
	{
		Node* t = head->prev;
		t->next = nn;
		nn->prev=t;
		nn->next = head;
		head->prev = nn;

	}
}
void myLL::displayFromTail()
{
	Node* t = head->prev;
	do {
		cout << t->data << endl;
		t = t->prev;
	} while (t != head->prev);
}