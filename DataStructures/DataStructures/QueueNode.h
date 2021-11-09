#pragma once

template <typename T> class QueueNode
{
private:
	QueueNode<T>* _next;
	T _value;

public:
	QueueNode<T>(T value, QueueNode<T>* lower);

	QueueNode<T>* Next();
	T Value();
};

template <class T>
QueueNode<T>::QueueNode(T value, QueueNode<T>* next)
{
	_value = value;
	_next = next;
}

template <typename T>
QueueNode<T>* QueueNode<T>::Next()
{
	return this->_next;
}

template <typename T>
T QueueNode<T>::Value()
{
	return this->_value;
}