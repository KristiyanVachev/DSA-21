#pragma once

template <typename T> class DynamicArray
{
private:
	T* data;
	int used;
	int capacity;

	void Reallocate(int newSize);

public:
	DynamicArray();
	~DynamicArray();

	void Add(T element);
	T* Data();
	int Lenght();
};

template <typename T>
void DynamicArray<T>::Reallocate(int newSize)
{
	T* temp = new T[newSize];

	for (int i = 0; i < this->used; i++)
	{
		temp[i] = this->data[i];
	}

	delete[] this->data;
	this->data = temp;
	this->capacity = newSize;
}

template <typename T>
DynamicArray<T>::DynamicArray()
{
	this->data = new T[0];
	this->used = 0;
	this->capacity = 0;
}

template <typename T>
DynamicArray<T>::~DynamicArray()
{
	this->capacity = 0;
	this->used = 0;
	delete[] this->data;
	this->data = nullptr;
}

template <typename T>
void DynamicArray<T>::Add(T element)
{
	if (this->capacity <= this->used)
	{
		int newSize = (this->capacity == 0) ? 2 : this->capacity * 2;

		Reallocate(newSize);
	}

	this->data[this->used] = element;
	this->used++;
}

template <typename T>
T* DynamicArray<T>::Data()
{
	return this->data;
}

template <typename T>
int DynamicArray<T>::Lenght()
{
	return this->used;
}