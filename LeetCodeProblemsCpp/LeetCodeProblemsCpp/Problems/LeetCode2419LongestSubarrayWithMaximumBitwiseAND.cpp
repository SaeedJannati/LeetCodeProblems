#include "LeetCode2419LongestSubarrayWithMaximumBitwiseAND.h"
using namespace std;

int LeetCode2419LongestSubarrayWithMaximumBitwiseAND::longestSubarray(vector<int>& nums)
{
    int max{};
    for (const auto& num : nums)
    {
      max= std::max(max,num);
    }
    int consecutiveCount{};
    int maxConsecutiveCount{};
    for (const auto& num : nums)
    {
        if (num==max)
        {
            consecutiveCount++;
            continue;
        }
        maxConsecutiveCount = std::max(maxConsecutiveCount, consecutiveCount);
        consecutiveCount = 0;
    }
    maxConsecutiveCount = std::max(maxConsecutiveCount, consecutiveCount);
    return  maxConsecutiveCount;
}
