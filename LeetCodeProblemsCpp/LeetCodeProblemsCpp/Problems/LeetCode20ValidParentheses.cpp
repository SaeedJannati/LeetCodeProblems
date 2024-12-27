#include "LeetCode20ValidParentheses.h"

#include <iostream>
#include <vector>

void LeetCode20ValidParentheses::Run()
{
    std::string input = "()";
    auto outPut = isValid(input) ? "true" : "false";
    std::cout << outPut << '\n';
}

bool LeetCode20ValidParentheses::isValid(std::string s)
{
    std::vector<char> stack{};
    int size = static_cast<int>(s.size());
    for (int i = 0; i < size; i++)
    {
        switch (s[i])
        {
        case '(':
        case '[':
        case '{':
            stack.push_back(s[i]);
            break;
        case ')':
            if(stack.empty())
                return false;
            if (stack.back() != '(')
                return false;
            stack.pop_back();
            break;
        case ']':
            if(stack.empty())
                return false;
            if (stack.back() != '[')
                return false;
            stack.pop_back();
            break;
        case '}':
            if(stack.empty())
                return false;
            if (stack.back() != '{')
                return false;
            stack.pop_back();
            break;
        }
    }
    if (!stack.empty())
        return false;
    return true;
}
