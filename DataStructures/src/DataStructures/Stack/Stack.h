#pragma once

#include "StackNode.h"

template <typename T> class Stack
{
private:
	StackNode<T>* _top;

public:
	Stack();
	Stack(const Stack& other) = delete;
	Stack& operator=(const Stack& other) = delete;
	~Stack();

	bool IsEmpty();
	void Push(T value);
	T Pop();
	T Peek();
};

template <typename T>
Stack<T>::Stack()
{
	this->_top = nullptr;
}

template <typename T>
Stack<T>::~Stack()
{
	StackNode<T>* currentNode = this->_top;

	while (currentNode != nullptr)
	{
		StackNode<T>* lowerNode = currentNode->Lower();

		delete currentNode;

		currentNode = lowerNode;
	}
}

template<typename T>
bool Stack<T>::IsEmpty()
{
	return this->_top == nullptr;
}

template<typename T>
void Stack<T>::Push(T value)
{
	StackNode<T>* newNode = new StackNode<T>(value, this->_top);

	this->_top = newNode;
}

template<typename T>
T Stack<T>::Pop()
{
	if (this->_top == nullptr)
	{
		return NULL;
	}

	StackNode<T>* node = this->_top;
	T value = node->Value();

	this->_top = node->Lower();
	delete node;

	return value;
}

template<typename T>
T Stack<T>::Peek()
{
	return this->_top->Value();
}