#include "iostream"
using namespace std;

#include "Stack.h"

//Better to have a class of constants
static const char OpeningBrackets[] = "{[(";
static const char ClosingBrackets[] = "}])";
static const int BracketsCount = sizeof(OpeningBrackets) / sizeof(OpeningBrackets[0]);

class BracketsValidator
{
private:
	bool IsBracket(char character);
	bool IsOpening(char character);
	bool BracketsMatch(char opening, char closing);

public:
	bool IsValid(char* sequence, int size);
};

inline bool BracketsValidator::IsValid(char* sequence, int size)
{
	Stack<char> openBrackets;

	for (size_t i = 0; i < size; i++)
	{
		if (!IsBracket(sequence[i]))
		{
			continue;
		}

		if (IsOpening(sequence[i]))
		{
			openBrackets.Push(sequence[i]);
		}
		else
		{
			char lastOpeningBracket = openBrackets.Pop();

			if (!BracketsMatch(lastOpeningBracket, sequence[i]))
			{
				return false;
			}
		}
	}

	if (!openBrackets.IsEmpty())
	{
		return false;
	}

	return true;
}


inline bool BracketsValidator::IsBracket(char character)
{
	if (IsOpening(character))
	{
		return true;
	}

	for (size_t i = 0; i < BracketsCount; i++)
	{
		if (character == ClosingBrackets[i])
		{
			return true;
		}
	}

	return false;
}

inline bool BracketsValidator::IsOpening(char character)
{
	//TODO How to get the size of the const array?
	for (size_t i = 0; i < BracketsCount; i++)
	{
		if (character == OpeningBrackets[i])
		{
			return true;
		}
	}

	return false;
}

inline bool BracketsValidator::BracketsMatch(char opening, char closing)
{
	for (size_t i = 0; i < BracketsCount; i++)
	{
		if (opening == OpeningBrackets[i])
		{
			if (closing == ClosingBrackets[i])
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}

	return false;
}

