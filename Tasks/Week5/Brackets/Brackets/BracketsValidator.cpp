#include "iostream"
using namespace std;

#include "Stack.h"

//const char* OpeningBrackets = new char[] {'{', '[', '('};
//const char* ClosingBrackets = new char[] {'}', ']', ')'};

//static const char* OpeningBrackets = "{[(";
//static const char* ClosingBrackets = "}])";

static const char OpeningBrackets[] = "{[(";
static const char ClosingBrackets[] = "}])";


class BracketsValidator
{
private:
	bool static IsBracket(char character)
	{
		if (IsOpening)
		{
			return true;
		}

		//TODO-Ask - can I not pass the size? How to get the size of the const array in a cool way?
		for (size_t i = 0; i < 3; i++)
		{
			if (character == ClosingBrackets[i])
			{
				return true;
			}
		}

		return false;
	}

	bool static IsOpening(char character)
	{
		//TODO How to get the size of the const array?
		for (size_t i = 0; i < 3; i++)
		{
			if (character == OpeningBrackets[i])
			{
				return true;
			}
		}

		return false;
	}

	bool static BracketsMatch(char opening, char closing)
	{
		for (size_t i = 0; i < 3; i++)
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

public:

	//TODO add declaration here.. but had a bug
	bool static IsValid(char* sequence, int size)
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

};
