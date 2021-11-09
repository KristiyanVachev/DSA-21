#include <string>
#include <iostream>

#include "BracketsValidator.cpp"

using namespace std;

string isBalanced(string s) {
	BracketsValidator* validator = new BracketsValidator();

	if (validator->IsValid(s))
	{
		return "YES";;
	}
	else
	{
		return "NO";;
	}
}

int main()
{
	string sequences[] =
	{
		"}][}}(}][))]",
		"[](){()}",
		"()",
		"({}([][]))[]()",
		"{)[](}]}]}))}(())(",
		"([[)"
	};

	for (size_t i = 0; i < 6; i++)
	{
		cout << isBalanced(sequences[i]) << endl;

	}


}
