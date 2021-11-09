#pragma once

#include "QueueNode.h"

template <typename T> class Queue
{
private:
	QueueNode<T>* _head;
	QueueNode<T>* _tail;
	int _size;

public:
	Queue();
	Queue(const Queue& other) = delete;
	Queue& operator=(const Queue& other) = delete;
	~Queue();

	bool IsEmpty();
	void Enqueue(T value);
	T Dequeue();
	T Peek();
	int Size();
};

template <typename T>
Queue<T>::Queue()
{
	this->_head = nullptr;
	this->_tail = nullptr;
	this->_size = 0;
}

template <typename T>
Queue<T>::~Queue()
{
	QueueNode<T>* currentNode = this->_head;

	while (currentNode != nullptr)
	{
		QueueNode<T>* lowerNode = currentNode->GetNextInLine();

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
	QueueNode<T>* newNode = new QueueNode<T>(value);

	if (this->_tail != nullptr)
	{
		this->_tail->SetNextInLine(newNode);
	}

	if (this->_head == nullptr)
	{
		this->_head = newNode;
	}

	this->_tail = newNode;
	this->_size++;
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

	this->_head = node->GetNextInLine();
	delete node;

	this->_size--;

	return value;
}

template<typename T>
T Queue<T>::Peek()
{
	return this->_head->Value();
}

template<typename T>
int Queue<T>::Size()
{
	return this->_size;
}