#pragma once

class Stack
{
private:
	char top;

public:
	Stack();
	~Stack();

	bool IsEmpty();
	void Add(char value);
	char Pop();

};

Stack::Stack()
{
	top = ' ';
}

Stack::~Stack()
{
	StackNode<char>* currentNode = this->_top;

	while (!(currentNode == nullptr))
	{
		StackNode<type>* lowerNode = currentNode->Lower();

		delete currentNode;

		currentNode = lowerNode;
	}
}

bool Stack::IsEmpty()
{
	return this->_top == nullptr;
}

void Stack::Add(char value)
{
	StackNode<type>* newNode = new StackNode<type>(value, this->_top);

	this->_top = newNode;
}

char Stack::Pop()
{
	StackNode<type>* node = this->_top;
	type* value = node->Value();

	this->_top = node->Lower();

	delete node;

	return value;
}