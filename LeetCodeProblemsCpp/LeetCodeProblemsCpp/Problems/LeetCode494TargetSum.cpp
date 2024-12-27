#include "LeetCode494TargetSum.h"

#include <iostream>
#include <numeric>
#include <ostream>

#pragma region DP
int LeetCode494TargetSum::findTargetSumWays(std::vector<int>& nums, int target)
{
    int length = static_cast<int>(nums.size());
    if (length == 0)
        return 0;
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if (abs(target) > sum) 
        return 0;
    int minValue = std::numeric_limits<int>::min();
    std::vector<std::vector<int>> dp(length, std::vector<int>(2 * sum+1 , minValue));
    return Recurse(nums, target, length-1 , dp, minValue, sum);
}

int LeetCode494TargetSum::Recurse(std::vector<int>& nums, int currentTarget, int index,
                                  std::vector<std::vector<int>>& dp, int minValue, int sum)
{
    if (index == 0)
    {
        return (currentTarget == nums[0]) + (currentTarget == -nums[0]);
    }
    int dpIndex = currentTarget + sum;
    if (dpIndex < 0 || dpIndex >= 2 * sum + 1) {
        return 0; 
    }
    if (dp[index][dpIndex] != minValue)
        return dp[index][dpIndex];
    dp[index][dpIndex] = Recurse(nums, currentTarget - nums[index], index - 1, dp, minValue, sum) +
        Recurse(nums, currentTarget + nums[index], index - 1, dp, minValue, sum);
    return dp[index][dpIndex];
}

void LeetCode494TargetSum::Run()
{
    std::vector<int> nums = {1,1,1,1,1};
    int target = 3;
    std::cout << findTargetSumWays(nums,target) << '\n';
}
#pragma endregion

#pragma region Backtracking
// int LeetCode494TargetSum::findTargetSumWays(std::vector<int>& nums, int target)
// {
//     int count = 0;
//     std::vector<int> sums;
//     int length = static_cast<int>(nums.size());
//     if (length == 0)
//         return 0;
//     if (length == 1)
//         return nums[0] == target || -nums[0] == target ? 1 : 0;
//     sums.push_back(nums[0]);
//     sums.push_back(-nums[0]);
//     int temp = 0;
//     for (int i = 1; i < length - 1; i++)
//     {
//         for (int j = 0, e = static_cast<int>(sums.size()); j < e; j++)
//         {
//             temp = sums[j];
//             sums[j] += nums[i];
//             sums.push_back(temp - nums[i]);
//         }
//     }
//     for (int j = 0, e = static_cast<int>(sums.size()); j < e; j++)
//     {
//         temp = sums[j];
//         if (temp + nums[length - 1] == target)
//             count++;
//         if (temp - nums[length - 1] == target)
//             count++;
//     }
//     return count;
// }
#pragma endregion
