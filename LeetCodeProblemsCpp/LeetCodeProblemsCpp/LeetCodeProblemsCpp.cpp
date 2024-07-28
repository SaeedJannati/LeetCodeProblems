
#include <iostream>

#include "Problems/LeetCode7ReverseInteger.h"
#include "Problems/LeetCode8StringToInteger.h"
#include "Problems/LeetCode9PalindromeNumber.h"

int main(int argc, char* argv[])
{
    const auto problem=new LeetCode9PalindromeNumber();
    problem->Run();
    delete problem;
}
