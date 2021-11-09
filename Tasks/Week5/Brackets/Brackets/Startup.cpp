#include <iostream>
#include "BracketsValidator.cpp"

using namespace std;

int main()
{
    char* sequence = new char[] {'[', ')'};

    BracketsValidator* validator = new BracketsValidator();

    cout << validator->IsValid(sequence, 2) << endl;

}
