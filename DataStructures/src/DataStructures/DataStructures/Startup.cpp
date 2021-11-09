#include <iostream>
#include "DynamicArray.h"

using namespace std;

int main()
{
	DynamicArray<int> arr;

	arr.Add(2);
	arr.Add(4);
	arr.Add(5);

	for (int i = 0; i < arr.Lenght(); i++)
	{
		cout << arr.Data()[i]<< endl;
	}

	return 0;
}
