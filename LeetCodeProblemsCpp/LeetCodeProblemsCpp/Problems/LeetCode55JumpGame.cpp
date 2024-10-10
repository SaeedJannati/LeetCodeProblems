#include "LeetCode55JumpGame.h"

#include <iostream>

void LeetCode55JumpGame::Run()
{
    std::vector<int> input = {3,2,1,0,4};
    auto outPut = canJump(input);
    std::cout << outPut?"true":"false";
}
//greedy
bool LeetCode55JumpGame::canJump(std::vector<int>& nums)
{
    if (nums.empty())
        return false;
    if (nums.size() == 1)
        return true;
   int maxReach=0;
    int size=static_cast<int>(nums.size());
    for (int i=0;i<size;i++)
    {
        if(i>maxReach)
            return false;
        maxReach=std::max(i+nums[i],maxReach);
        if(maxReach>=size-1)
            return true;
    }
    return true;
}
//dp
// bool LeetCode55JumpGame::canJump(std::vector<int>& nums)
// {
//     if (nums.empty())
//         return false;
//     if (nums.size() == 1)
//             return true;
//     if (nums[0] <= 0)
//         return false;
//     auto size = static_cast<int>(nums.size());
//     std::vector<int> dp(size, 0);
//     int upperBound = 0;
//     for (int i = 0; i < size; i++)
//     {
//         if(i>0 && dp[i]==0)
//             return false;
//         upperBound = std::min(i + nums[i], size - 1);
//         for (int j = i+1; j <= upperBound; j++)
//             dp[j]++;
//     }
//     return dp[size - 1] > 0;
// }
