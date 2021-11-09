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