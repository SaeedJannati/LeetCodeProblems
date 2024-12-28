#include "LeetCode689MaximumSumof3NonOverlappingSubarrays.h"

#include "Auxilaries.h"

std::vector<int> LeetCode689MaximumSumof3NonOverlappingSubarrays::maxSumOfThreeSubarrays
(std::vector<int>& nums, int k)
{
    int length = static_cast<int>(nums.size());
    int dpLength = length - k + 1;
    std::vector<double> sum(dpLength, 0);
    for (int i = 0; i < k; i++)
    {
        sum[0] += nums[i];
    }
    for (int i = k; i < length; i++)
    {
        sum[i - k + 1] = sum[i - k] - nums[i - k] + nums[i];
    }
    int minDouble=std::numeric_limits<double>::min();
    std::vector<std::vector<double>> prefixSum(dpLength, std::vector<double>(2, minDouble));
    std::vector<std::vector<double>> suffixSum(dpLength, std::vector<double>(2, minDouble));
    int maxSuffixIndex=0;
    int maxPrefixIndex=0;
    double maxSuffixSum=0;
    double maxPrefixSum=0;
    for (int i = 0; i <= dpLength-k-1; i++)
    {
        if (sum[i] > maxPrefixSum)
        {
            maxPrefixSum = sum[i];
            maxPrefixIndex = i;
        }
        if (sum[dpLength-i-1] >= maxSuffixSum)
        {
            maxSuffixSum = sum[dpLength-i-1];
            maxSuffixIndex = dpLength-i-1;
        }
        prefixSum[i+k][0]=maxPrefixSum;
        prefixSum[i+k][1]=maxPrefixIndex;
        suffixSum[dpLength-k-1-i][0]=maxSuffixSum;
        suffixSum[dpLength-k-1-i][1]=maxSuffixIndex;
    }
    double maxSum = minDouble;
    int maxIndex = 0;
    double currentSum=0;
    for (int i = k,e=dpLength-k; i <e ; i++)
    {
        currentSum=prefixSum[i][0]+suffixSum[i][0]+sum[i];
        if (currentSum > maxSum)
        {
            maxSum = currentSum;
            maxIndex = i;
        }
    }
    return std::vector<int>{static_cast<int>( prefixSum[maxIndex][1]),maxIndex,static_cast<int>(suffixSum[maxIndex][1])};
}

void LeetCode689MaximumSumof3NonOverlappingSubarrays::Run()
{
    std::vector<int> nums = {7,13,20,19,19,2,10,1,1,19};
    int k = 3;
    auto result = maxSumOfThreeSubarrays(nums, k);
    Auxilaries::PrintVector(result);
}
