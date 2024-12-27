#include "LeetCode45JumpGameII.h"

#include <iostream>
#include <ostream>

void LeetCode45JumpGameII::Run()
{
    std::vector<int> input = {7, 0, 9, 6, 9, 6, 1, 7, 9, 0, 1, 2, 9, 0, 3};
    auto jumpCount = jump(input);
    std::cout << jumpCount << '\n';
}

//Greedy
int LeetCode45JumpGameII::jump(std::vector<int>& nums)
{
    int size = static_cast<int>(nums.size());
    if (size <= 1)
        return 0;
    int jumpCount = 0;
    int farthest = 0;
    int currentJumpEnd = 0;
    for (int i = 0; i < size; i++)
    {
        farthest = std::max(i + nums[i], farthest);
        if (currentJumpEnd == i)
        {
            currentJumpEnd = farthest;
            jumpCount++;
            if (currentJumpEnd >= size - 1)
                break;
        }
    }
    return jumpCount;
}


//Dp
// int LeetCode45JumpGameII::jump(std::vector<int>& nums)
// {
//     int size = static_cast<int>(nums.size());
//     if (size <= 1)
//         return 0;
//     std::vector<int> dp(size, 0);
//     int upperBound{0};
//     for (int i = 0; i < size; i++)
//     {
//         upperBound=std::min(nums[i]+i,size-1);
//         for (int j=i+1; j <= upperBound; j++)
//         {
//             if(dp[j] ==0)
//             {
//                 dp[j] = dp[i]+1;
//                 continue;
//             }
//             dp[j] = std::min(dp[i]+1,dp[j]);
//         }
//          
//     }
//     return dp[size-1];
// }
