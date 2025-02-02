#include"myLL.h"
int main() {
	myLL obj;
	obj.insertSorted(99);
	obj.insertSorted(12);
	obj.insertSorted(9);
	obj.insertSorted(13);
	obj.insertSorted(1);
	obj.displayFromHead();

	cout << "Delete Value from Tail is" << obj.deleteFromTail() << endl;

	obj.displayFromHead();
	

	cout << endl << "Max Element in the Linked List is" << obj.maxElement() << endl;
	obj.Factorial();
	cout << "Sum of Elements Of Linked List is" << obj.sumOfLL() << endl;
	cout << endl << "Second Max Element in the Linked List is" << obj.findSecondMax() << endl;




	return 0;
}