#include "LeetCode1323Maximum69Number.h"

#include <stack>

int LeetCode1323Maximum69Number::maximum69Number(int num)
{
    std::stack<int> digits{};
    while (num>0)
    {
        digits.push(num%10);
        num /= 10;
    }
    int result = 0;
    bool changed = false;
    while (!digits.empty())
    {
        if (digits.top()==6)
        {
            if (!changed)
            {
                result+=9;
                changed = true;
            }
            else
            {
                result+=6;
            }
        }
        else
        {
            result += digits.top();
        }
        digits.pop();
        result *= 10;
    }
    return result/10;
}
