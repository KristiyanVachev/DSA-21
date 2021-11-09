#pragma once

#include "QueueNode.h"

template <typename T> class Queue
{
private:
	QueueNode<T>* _head;
	QueueNode<T>* _tail;

public:
	Queue();
	Queue(const Queue& other) = delete;
	Queue& operator=(const Queue& other) = delete;
	~Queue();

	bool IsEmpty();
	void Enqueue(T value);
	T Dequeue();
	T Peek();
};

template <typename T>
Queue<T>::Queue()
{
	this->_head = nullptr;
	this->_tail = nullptr;
}

template <typename T>
Queue<T>::~Queue()
{
	QueueNode<T>* currentNode = this->_head;

	while (currentNode != nullptr)
	{
		QueueNode<T>* lowerNode = currentNode->Next();

		delete currentNode;

		currentNode = lowerNode;
	}
}

template<typename T>
bool Queue<T>::IsEmpty()
{
	return this->_head == nullptr;
}

template<typename T>
void Queue<T>::Enqueue(T value)
{
	QueueNode<T>* newNode = new QueueNode<T>(value, this->_tail);

	if (this->_head == nullptr)
	{
		this->_head = newNode;
	}

	this->_tail = newNode;
}

template<typename T>
T Queue<T>::Dequeue()
{
	if (this->_head == nullptr)
	{
		return NULL;
	}

	QueueNode<T>* node = this->_head;
	T value = node->Value();

	this->_head = node->Next();
	delete node;

	return value;
}

template<typename T>
T Queue<T>::Peek()
{
	return this->_head->Value();
}