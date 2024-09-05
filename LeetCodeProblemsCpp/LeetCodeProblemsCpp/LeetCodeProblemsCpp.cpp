#include <iostream>

#include "Problems/LeetCode105ConstructBinaryTreeFromPreorderAndInorderTraversal.h"
#include "Problems/LeetCode20ValidParentheses.h"

int main(int argc, char* argv[])
{
    const auto problem = new LeetCode105ConstructBinaryTreeFromPreorderAndInorderTraversal();
    problem->Run();
    delete problem;
}
