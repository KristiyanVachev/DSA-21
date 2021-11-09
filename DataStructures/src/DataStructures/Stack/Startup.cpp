#include <iostream>
#include "Stack.h"

int main()
{
    Stack<int> stack;

    stack.Push(2);
    stack.Push(4);
    stack.Push(8);
    stack.Push(16);
    
    std::cout << stack.Pop() << std::endl;
}
