#pragma once

template <typename T> class StackNode
{
private:
	StackNode<T>* _lowerNode;
	T _value;

public:
	StackNode<T>(T value, StackNode<T>* lower);
	~StackNode();

	StackNode<T>* Lower();
	T Value();
};

template <class T>
StackNode<T>::StackNode(T value, StackNode<T>* lower)
{
	_value = value;
	_lowerNode = lower;
}

template <typename T>
StackNode<T>::~StackNode()
{

}


template <typename T>
StackNode<T>* StackNode<T>::Lower()
{
	return this->_lowerNode;
}

template <typename T>
T StackNode<T>::Value()
{
	return this->_value;
}