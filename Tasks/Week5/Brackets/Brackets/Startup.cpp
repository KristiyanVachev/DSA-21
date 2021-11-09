#include <iostream>
#include <string>
#include <vector>
#include "BracketsValidator.cpp"

using namespace std;

int main()
{
	string sequence = "[]";

	string sequences[] =
	{
		"}][}}(}][))]",
		"[](){()}",
		"()",
		"({}([][]))[]()",
		"{)[](}]}]}))}(())(",
		"([[)"
	};

	BracketsValidator * validator = new BracketsValidator();

	for (size_t i = 0; i < 6; i++)
	{
		if (validator->IsValid(sequences[i]))
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}


}
