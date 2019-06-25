#ifndef QUEUE_H
#define QUEUE_H

#include"list.h"

template<typename Type>
class Queue {
public:

	Queue();
	void	push(Type item);
	void	pop();
	Type	peek() const;
	bool	isEmpty() const;
	void	printQueue() const;

private:

	List<Type> m_list;
};

template<typename Type>
Queue<Type>::Queue() :m_list() {}

template<typename Type>
void Queue<Type>::push(Type item) {
	m_list.addToRear(item);
}

template<typename Type>
void Queue<Type>::pop() {
	m_list.deleteFront();
}

template<typename Type>
bool Queue<Type>::isEmpty() const {
	return m_list.isEmpty();
}

template<typename Type>
Type Queue<Type>::peek() const {
	return m_list.getFront();
}

template<typename Type>
void Queue<Type>::printQueue() const {
	m_list.printItems();
}

#endif