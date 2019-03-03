#ifndef LIST_H
#define LIST_H

#include<iostream>
#include<assert.h>

template<typename Type>
class List {
public:

	List();
	~List();

	void	printItems() const;
	bool	isEmpty() const;

	void	addToFront(Type item);
	void	addToRear(Type item);
	void	addItem(int index, Type item);

	Type	getFront() const;
	Type	getRear() const;
	Type	getItem(int index) const;


	int		getSize() const;
	int		findItem(Type item) const;

	bool	deleteFront();
	bool	deleteRear();
	bool	deleteItem(int index);

private:

	class	Node;
	Node*	head;
	Node*	tail;
	int		size;
};

template<typename Type>
class List<Type>::Node {
public:
	Node() :next(nullptr) {}
	Node(Type item, Node* next) : item(item), next(next) {}

	Type  item;
	Node* next;
};

template<typename Type>
List<Type>::List() {

	head = nullptr;
	tail = nullptr;
	size = 0;
}

template<typename Type>
List<Type>::~List() {

	if (head == nullptr) {
		return;
	}
	else {
		Node *temp;
		temp = head;
		for (int i = 0; i < size; i++) {
			Node *nextTemp = temp->next;
			delete temp;
			temp = nextTemp;
		}
	}

}

template<typename Type>
void List<Type>::printItems() const {

	if (head == nullptr || size == 0) {
		std::cout << "Nothing to print..." << std::endl;
	}
	else {
		Node* temp;
		temp = head;
		std::cout << "Head ";
		for (int i = 0; i < size; i++) {
			std::cout << temp->item << " ";
			temp = temp->next;
		}
		std::cout << " Tail" << std::endl;
	}

}

template<typename Type>
bool List<Type>::isEmpty() const {

	if (head == nullptr || size == 0) return true;
	return false;

}

template<typename Type>
void List<Type>::addToFront(Type item) {

	Node* newItem = new Node;

	if (head == nullptr) {
		newItem->next = nullptr;
		newItem->item = item;
		head = newItem;
		tail = newItem;
		size++;
	}
	else {
		newItem->next = head;
		newItem->item = item;
		head = newItem;
		size++;
	}

}

template<typename Type>
void List<Type>::addToRear(Type item) {

	Node* newItem = new Node;

	if (head == nullptr) {
		newItem->next = nullptr;
		newItem->item = item;
		head = newItem;
		tail = newItem;
		size++;
	}
	else {
		tail->next = newItem;
		newItem->next = tail;
		newItem->item = item;
		tail = newItem;
		size++;
	}

}

template<typename Type>
void List<Type>::addItem(int index, Type item) {

	Node* temp = new Node;
	Node* newItem = new Node;

	if (head == nullptr) {
		newItem->next = nullptr;
		newItem->item = item;
		head = newItem;
		tail = newItem;
		size++;
	}
	else if (index <= 0) {
		newItem->next = nullptr;
		newItem->item = item;
		head = newItem;
		tail = newItem;
		size++;
	}
	else if (index >= size) {
		addToRear(item);
	}
	else {
		temp = head;
		for (int i = 0; i < index; i++) {
			Node *nextTemp = temp->next;
			temp = nextTemp;
		}
		Node *nextTemp = temp->next;
		temp->next = newItem;
		newItem->next = nextTemp;
		newItem->item = item;
		size++;
	}

}

template<typename Type>
Type List<Type>::getFront() const {

	assert(head != nullptr);

	Node* temp = new Node;
	temp = head;

	return temp->item;

}

template<typename Type>
Type List<Type>::getRear() const {

	assert(tail != nullptr);

	return tail->item;
}

template<typename Type>
Type List<Type>::getItem(int index) const {

	assert(index >= 0 && index < size);

	Node* temp = new Node;
	temp = head;

	for (int i = 0; i < index; i++) {
		Node *nextTemp = temp->next;
		temp = nextTemp;
	}

	return temp->item;

}

template<typename Type>
int List<Type>::getSize() const {

	return size;

}

template<typename Type>
int List<Type>::findItem(Type item) const {

	Node* temp = new Node;
	temp = head;

	for (int i = 0; i < size; i++) {
		if (temp->item == item) {
			return i;
		}
		else {
			temp = temp->next;
		}

	}

	return -1;
}
	
template<typename Type>
bool List<Type>::deleteFront() {

	if (head == nullptr) {
		return 0;
	}
	else {
		Node* firstItem = new Node;
		Node* secondItem = new Node;
		firstItem = head;
		secondItem = firstItem->next;
		head = secondItem;
		delete firstItem;
		size--;
	}

	return false;
}

template<typename Type>
bool List<Type>::deleteRear() {

	if (tail == nullptr) {
		return false;
	}
	else {
		Node* temp = new Node;
		temp = head;
		for (int i = 0; i < size - 2; i++) {
			temp = temp->next;
		}
		temp->next = tail;
		tail = temp;
		size--;

		return true;
	}
	return false;
}

template<typename Type>
bool List<Type>::deleteItem(int index) {

	Node* temp = new Node;

	if (head == nullptr) {
		return false;
	}
	else if (index < 0) {
		return false;
	}
	else if (index >= size) {
		return false;
	}
	else if (index == 0) {
		return deleteFront();
	}
	else {
		temp = head;
		for (int i = 0; i < index - 1; i++) {
			temp = temp->next;
		}
		Node *nextTemp = temp->next;
		temp->next = nextTemp->next;
		delete nextTemp;

		size--;

		return true;

	}

	return false;

}

#endif//LIST_H