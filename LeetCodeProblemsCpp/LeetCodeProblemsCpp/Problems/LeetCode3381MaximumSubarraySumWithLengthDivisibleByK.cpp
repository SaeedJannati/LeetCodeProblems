#include "LeetCode3381MaximumSubarraySumWithLengthDivisibleByK.h"

#include <algorithm>
#include <iostream>
#include <ostream>
using namespace std;

long long LeetCode3381MaximumSubarraySumWithLengthDivisibleByK::maxSubarraySum(vector<int>& nums, int k)
{
    int length = static_cast<int>(nums.size());
    vector<long long> prefixSum(length, 0);
    for (int i = 1; i < length; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
    }
    long long maxSum = INT64_MIN;
    long long currentSum = 0;
    vector<long long> maxSums(length, INT64_MIN);
    maxSums[k - 1] = prefixSum[k - 1] + nums[k - 1];
    maxSum = maxSums[k-1];
    for (int i = k; i < length; ++i)
    {
        currentSum = prefixSum[i] - prefixSum[i - k + 1] + nums[i];
        if (maxSums[i - k] == INT64_MIN)
        {
            maxSums[i] = currentSum;
        }
        else
        {
            maxSums[i] = max(maxSums[i - k] + currentSum, currentSum);
        }
        maxSum = max(maxSums[i], maxSum);
    }
    return maxSum;
}

void LeetCode3381MaximumSubarraySumWithLengthDivisibleByK::Run()
{
    vector<int> nums{-1, -2, -3, -4, -5};
    int k = 4;
    cout << maxSubarraySum(nums, k) << endl;
}
