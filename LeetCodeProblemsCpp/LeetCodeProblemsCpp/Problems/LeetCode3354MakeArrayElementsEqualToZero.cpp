#include "LeetCode3354MakeArrayElementsEqualToZero.h"

int LeetCode3354MakeArrayElementsEqualToZero::countValidSelections(std::vector<int>& nums)
{
    int length = static_cast<int>(nums.size());
    std::vector<int> prefixSum(length,0);
    std::vector<int> suffixSum(length,0);
    for (int i=1;i<length;i++)
    {
        prefixSum[i]=prefixSum[i-1]+nums[i-1];
    }
    for (int i=length-2;i>=0;i--)
    {
        suffixSum[i]=suffixSum[i+1]+nums[i+1];
    }
    int validCount{};
    for (int i=0;i<length;i++)
    {
        if (nums[i]!=0)
        {
            continue;
        }
        if (prefixSum[i]==suffixSum[i])
        {
            validCount+=2;
            continue;
        }
        if ( abs(prefixSum[i]-suffixSum[i])==1)
        {
            validCount+=1;
            continue;
        }
    }
    return validCount;
}
