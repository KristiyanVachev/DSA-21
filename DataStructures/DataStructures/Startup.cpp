#include <iostream>

#include "DynamicArray.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;

void RunDynamicArray()
{
	cout << "Running dynamic array..." << endl;

	DynamicArray<int> arr;

	arr.Add(2);
	arr.Add(4);
	arr.Add(5);

	for (int i = 0; i < arr.Lenght(); i++)
	{
		cout << arr.Data()[i] << endl;
	}
}

void RunStack()
{
	cout << "Running stack..." << endl;

	Stack<int> stack;

	stack.Push(2);
	stack.Push(4);
	stack.Push(8);
	stack.Push(16);

	cout << stack.Pop() << endl;
}

void RunQueue()
{
	cout << "Running queue..." << endl;

	Queue<int> queue;

	queue.Enqueue(2);
	queue.Enqueue(4);
	queue.Enqueue(16);
	queue.Enqueue(32);

	cout << queue.Dequeue() << endl;
}

int main()
{
	RunDynamicArray();
	RunStack();
	RunQueue();

	return 0;
}
