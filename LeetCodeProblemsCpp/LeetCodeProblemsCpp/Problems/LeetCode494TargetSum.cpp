#include "LeetCode494TargetSum.h"

#include <list>

int LeetCode494TargetSum::findTargetSumWays(std::vector<int>& nums, int target)
{
    int count = 0;
    std::vector<int> sums;
    int length = static_cast<int>(nums.size());
    if (length == 0)
        return 0;
    if (length == 1)
        return nums[0] == target || -nums[0] == target ? 1 : 0;
    sums.push_back(nums[0]);
    sums.push_back(-nums[0]);
    int temp = 0;
    for (int i = 1; i < length - 1; i++)
    {
        for (int j = 0, e = static_cast<int>(sums.size()); j < e; j++)
        {
            temp = sums[j];
            sums[j] += nums[i];
            sums.push_back(temp - nums[i]);
        }
    }
    for (int j = 0, e = static_cast<int>(sums.size()); j < e; j++)
    {
        temp = sums[j];
        if (temp + nums[length - 1] == target)
            count++;
        if (temp - nums[length - 1] == target)
            count++;
    }
    return count;
}
