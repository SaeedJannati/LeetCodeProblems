#include "LeetCode1304FindNUniqueIntegersSumUpToZero.h"

std::vector<int> LeetCode1304FindNUniqueIntegersSumUpToZero::sumZero(int n)
{
    std::vector<int> res{};
    res.reserve(n );
    if (n%2==1)
    {
        res.push_back(0);
    }
    for (int i=1;i<=n/2;i++)
    {
        res.push_back(i);
        res.push_back(-i);
    }
    return res;
}
