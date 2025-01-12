#include "LeetCode2116CheckIfAParenthesesStringCanBeValid.h"

#include <iostream>
#include <stack>

bool LeetCode2116CheckIfAParenthesesStringCanBeValid::canBeValid(std::string s, std::string locked)
{
    int size = static_cast<int>(s.size());
    if (size % 2 == 1)
        return false;
    std::stack<int> unlockedStack;
    std::stack<int> lockedOpenStack;
    
    for (int i = 0; i < size; i++)
    {
        if (locked[i] == '0')
        {
            unlockedStack.push(i);
            continue;
        }
        if (s[i]=='(')
        {
            lockedOpenStack.push(i);
            continue;
        }
        if (!lockedOpenStack.empty())
        {
            lockedOpenStack.pop();
            continue;
        }
        if (!unlockedStack.empty())
        {
            unlockedStack.pop();
            continue;
        }
        return false;
    }
    while (!lockedOpenStack.empty())
    {
        if (unlockedStack.empty())
            return false;
        if (lockedOpenStack.top() > unlockedStack.top())
            return false;
        lockedOpenStack.pop();
        unlockedStack.pop();
    }
    if (unlockedStack.empty())
        return true;
    return unlockedStack.size()%2==0;
}

void LeetCode2116CheckIfAParenthesesStringCanBeValid::Run()
{
    std::string s = ")(";
    // "))()))";
    std::string locked = "0";
    // "010100";
    std::cout << canBeValid(s, locked);
}
