#include <iostream>

#include "Stack.h"
#include "BracketsValidator.cpp"

using namespace std;

int main()
{
    //Stack<int> stack;

    //std::cout << stack.IsEmpty() << std::endl;

    //stack.Push(2);
    //stack.Push(4);

    //std::cout << stack.Pop() << std::endl;
    //std::cout << stack.IsEmpty() << std::endl;

    //std::cout << stack.Pop() << std::endl;
    //std::cout << stack.IsEmpty() << std::endl;


    char* sequence = new char[] {'[', ')'};

    cout << BracketsValidator::IsValid(sequence, 2) << endl;

}
