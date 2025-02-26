#include "LeetCode1749MaximumAbsoluteSumOfAnySubarray.h"

#include <algorithm>

int LeetCode1749MaximumAbsoluteSumOfAnySubarray::maxAbsoluteSum(std::vector<int>& nums)
{
    int length = nums.size();
    long prefixSum = 0;
    int minPrefixSum = 0;
    int maxPrefixSum = 0;
    for (int i = 0; i < length; i++)
    {
        prefixSum += nums[i];
        maxPrefixSum = std::max<long>(prefixSum, maxPrefixSum);
        minPrefixSum = std::min<long>(prefixSum, minPrefixSum);
    }
    return maxPrefixSum - minPrefixSum;
}
