#include "LeetCode416PartitionEqualSubsetSum.h"

#include <iostream>
#include <numeric>
using namespace std;

bool LeetCode416PartitionEqualSubsetSum::canPartition(std::vector<int>& nums)
{
    int sum{};
    sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 == 1)
        return false;
    int length = static_cast<int>(nums.size());
    auto dp = vector(sum / 2 + 1, vector(length + 1, 0));
    for (int i = 0; i <= length; ++i)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= sum / 2; ++i)
    {
        dp[i][0] = 0;
    }
    for (int j = 1; j < sum / 2+1; j++)
    {
        for (int i = 1; i < length + 1; i++)
        {
            int previous = j - nums[i - 1] >= 0 ? dp[j - nums[i - 1]][i - 1] : 0;
            dp[j][i] =max( previous + nums[i - 1],dp[j][i-1]);
            if (dp[j][i] == sum / 2)
            {
                return true;
            }
            if (dp[j][i] > j)
            {
                dp[j][i] = dp[j][i-1];
            }
        }
    }
    return false;
}

void LeetCode416PartitionEqualSubsetSum::Run()
{
    vector<int> nums = {1,2,3,4,5,6,7};
    bool result = canPartition(nums);
    cout << "Result: " << result << endl;
}
