#ifndef STACK_H
#define STACK_H

#include"list.h"

template<typename Type>
class Stack {
public:

	Stack();
	void	push(Type item);
	void	pop();
	Type	peek() const; 
	bool	isEmpty() const;
	void	printStack() const;

private:

	List<Type> m_list;
};

template<typename Type>
Stack<Type>::Stack():m_list() {}

template<typename Type>
void Stack<Type>::push(Type item) {
	m_list.addToRear(item);
}

template<typename Type>
void Stack<Type>::pop() {
	m_list.deleteRear();
}

template<typename Type>
bool Stack<Type>::isEmpty() const {
	return m_list.isEmpty();
}

template<typename Type>
Type Stack<Type>::peek() const {
	return m_list.getRear();
}

template<typename Type>
void Stack<Type>::printStack() const {
	m_list.printItems();
}
#endif