#include "LinkedList.h"

template <typename T>
class myLL : public LinkedList<T> {
public:
    void insertAtHead(T);
    void displayFromHead();
    void insertAtTail(T);
    void displayFromTail();
    T deleteFromHead();
    T maxElement();
   // void Factorial();
    T sumOfLL();
    void insertSorted(T);
    T deleteFromTail();
    void deleteEvenNodes();
    T findSecondMax();
    void displayRecursive();
    //void displayFromTailRecursive();
    void deleteduplicate();
private:
    void displayRecursiveHelper(Node<T>* node, Node<T>* head);
    //void displayFromTailRecursiveHelper(Node<T>* node, Node<T>* tail);
};
template<typename t>
void myLL<t>::displayRecursive() {
    if (this->head == nullptr) {
        std::cout << "List is empty!" << std::endl;
        return;
    }
    displayRecursiveHelper(this->head, this->head); 
    cout << endl;
}
//template<typename t>
//void myLL<t>::displayFromTailRecursive() {
//    if (this->tail == nullptr) {
//        std::cout << "List is empty!" << std::endl;
//        return;
//    }
//    displayFromTailRecursiveHelper(this->tail, this->tail);
//    cout << endl;
//}
template<typename T>
void myLL<T>::displayRecursiveHelper(Node<T>* node, Node<T>* head) {
    if (node == nullptr) return; 

    cout << node->data << " ";
    if (node->next != head) {
        displayRecursiveHelper(node->next, head); 
    }
}
template <typename t> 
void myLL<t>::deleteduplicate() {
    		if (this->head==nullptr) {
    			return;
    		}
    		else {
    			Node <t>* temp1 = this->head;
    			while (true) {
    				Node <t>* temp2 = temp1->next;
    				while (temp2 != this->head) {
    					if (temp1->data == temp2->data) {
    						Node <t>* todel = temp2;
    						temp2->prev->next = temp2->next;
    						temp2->next->prev = temp2->prev;
    						temp2 = temp2->next;
    						delete todel;
    					}
    					else {
    						temp2 = temp2->next;
    					}
    				}
    				temp1 = temp1->next;
    				if (temp1 == this->head) {
    					break;
    				}
    			}
    		}
    	}
//template<typename T>
//void myLL<T>::displayFromTailRecursiveHelper(Node<T>* node, Node<T>* tail) {
//    if (node == nullptr) return;
//
//    cout << node->data << " ";
//    if (node->prev != tail) {
//        displayFromTailRecursiveHelper(node->prev, tail);
//    }
//}


template <typename T>
T myLL<T>::findSecondMax() {
    if (!this->head || this->head->next == this->head) {
        return T();
    }
    T maxval = this->head->data;
    T secMaxVal = this->head->data;
    Node<T>* temp = this->head;
    do {
        if (temp->data > maxval) {
            secMaxVal = maxval;
            maxval = temp->data;
        }
        else if (temp->data > secMaxVal && temp->data != maxval) {
            secMaxVal = temp->data;
        }
        temp = temp->next;
    } while (temp != this->head);
    return secMaxVal;
}

template <typename T>
void myLL<T>::deleteEvenNodes() {
    if (!this->head) {
        return;
    }
    Node<T>* temp = this->head;
    do {
        Node<T>* nextnode = temp->next;
        if (temp->data % 2 == 0) {
            if (temp->next == temp) {
                delete temp;
                this->head = nullptr;
                return;
            }
            else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                if (temp == this->head) {
                    this->head = temp->next;
                }
                delete temp;
            }
        }
        temp = nextnode;
    } while (temp != this->head);
}

template <typename T>
void myLL<T>::insertSorted(T value) {
    if (this->head == nullptr) {
        Node<T>* nn = new Node<T>;
        nn->data = value;
        nn->next = nn;
        nn->prev = nn;
        this->head = nn;
    }
    else if (value <= this->head->data) {
        insertAtHead(value);
    }
    else if (value >= this->head->prev->data) {
        insertAtTail(value);
    }
    else {
        Node<T>* nn = new Node<T>;
        nn->data = value;
        Node<T>* t = this->head;
        while (true) {
            if (value >= t->data && value <= t->next->data) {
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

template <typename T>
T myLL<T>::deleteFromTail() {
    if (this->head == nullptr) {
        return T();
    }
    else if (this->head == this->head->next) {
        T returningValue = this->head->data;
        delete this->head;
        this->head = nullptr;
        return returningValue;
    }
    else {
        T returningValue = this->head->prev->data;
        Node<T>* t = this->head->prev->prev;
        delete this->head->prev;
        t->next = this->head;
        this->head->prev = t;
        return returningValue;
    }
}

template <typename T>
T myLL<T>::deleteFromHead() {
    if (this->head == nullptr) {
        return T();
    }
    else if (this->head == this->head->next) {
        T returningValue = this->head->data;
        delete this->head;
        this->head = nullptr;
        return returningValue;
    }
    else {
        T returningValue = this->head->data;
        Node<T>* t = this->head->prev;
        this->head = this->head->next;
        delete this->head->prev;
        t->next = this->head;
        this->head->prev = t;
        return returningValue;
    }
}

template <typename T>
T myLL<T>::sumOfLL() {
    if (!this->head) return T();
    Node<T>* t = this->head;
    T sum = T();
    do {
        sum += t->data;
        t = t->next;
    } while (t != this->head);
    return sum;
}

//template <typename T>
//void myLL<T>::Factorial() {
//    if (!this->head) return;
//    Node<T>* t = this->head;
//    do {
//        T fact = 1;
//        for (T i = t->data; i > 0; i--) {
//            fact *= i;
//        }
//        t = t->next;
//    } while (t != this->head);
//}

template <typename T>
T myLL<T>::maxElement() {
    if (!this->head) return T();
    Node<T>* t = this->head;
    T maxVal = this->head->data;
    do {
        if (t->data > maxVal) {
            maxVal = t->data;
        }
        t = t->next;
    } while (t != this->head);
    return maxVal;
}

template <typename T>
void myLL<T>::insertAtHead(T value) {
    Node<T>* nn = new Node<T>;
    nn->data = value;
    if (this->head == nullptr) {
        nn->next = nn;
        nn->prev = nn;
        this->head = nn;
    }
    else {
        Node<T>* t = this->head->prev;
        this->head->prev = nn;
        nn->prev = t;
        nn->next = this->head;
        t->next = nn;
        this->head = nn;
    }
}

template <typename T>
void myLL<T>::displayFromHead() {
    if (!this->head) return;
    Node<T>* t = this->head;
    do {
        t = t->next;
    } while (t != this->head);
}

template <typename T>
void myLL<T>::insertAtTail(T value) {
    Node<T>* nn = new Node<T>;
    nn->data = value;
    if (this->head == nullptr) {
        nn->next = nn;
        nn->prev = nn;
        this->head = nn;
    }
    else {
        Node<T>* t = this->head->prev;
        t->next = nn;
        nn->prev = t;
        nn->next = this->head;
        this->head->prev = nn;
    }
}

template <typename T>
void myLL<T>::displayFromTail() {
    if (!this->head) return;
    Node<T>* t = this->head->prev;
    do {
        t = t->prev;
    } while (t != this->head->prev);
}
