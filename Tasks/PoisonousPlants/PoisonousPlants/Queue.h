#pragma once

template <typename T> class QueueNode
{
private:
	QueueNode<T>* _nextInLine;
	T _value;

public:
	QueueNode<T>(T value);

	QueueNode<T>* GetNextInLine();
	void SetNextInLine(QueueNode<T>* nextInLine);
	T Value();
};

template <class T>
QueueNode<T>::QueueNode(T value)
{
	_value = value;
	_nextInLine = nullptr;
}

template <typename T>
QueueNode<T>* QueueNode<T>::GetNextInLine()
{
	return this->_nextInLine;
}

template <typename T>
void QueueNode<T>::SetNextInLine(QueueNode<T>* nextInLine)
{
	_nextInLine = nextInLine;
}

template <typename T>
T QueueNode<T>::Value()
{
	return this->_value;
}


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