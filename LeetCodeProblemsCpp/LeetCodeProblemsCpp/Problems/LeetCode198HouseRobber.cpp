#include "LeetCode198HouseRobber.h"

#include <iostream>
#include <ostream>

void LeetCode198HouseRobber::Run()
{
    std::vector<int> input={2,7,9,3,1};
    auto robbingAmount=rob(input);
    std::cout<<robbingAmount<<'\n';
}

int LeetCode198HouseRobber::rob(std::vector<int>& nums)
{
    if (nums.empty())
        return 0;
    if (nums.size() == 1)
        return nums[0];
    if (nums.size() == 2)
        return std::max(nums[0] , nums[1]);
    std::vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    dp[1] = nums[1];
    dp[2] = nums[2]+nums[0];
    int size=static_cast<int>(nums.size());
    for (int i = 3; i <size ; i++)
    {
        dp[i] =  std::max(dp[i-2], dp[i-3])+ nums[i];
        
    }
    return std::max(dp[size-1], dp[size-2]);
}
