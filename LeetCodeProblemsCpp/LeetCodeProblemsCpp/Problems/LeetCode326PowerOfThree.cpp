#include "LeetCode326PowerOfThree.h"

bool LeetCode326PowerOfThree::isPowerOfThree(int n)
{
    if (n<=0)
        return false;
    int maxPowIntPowerOfThree = 1162261467;
    return maxPowIntPowerOfThree %n==0;
}
