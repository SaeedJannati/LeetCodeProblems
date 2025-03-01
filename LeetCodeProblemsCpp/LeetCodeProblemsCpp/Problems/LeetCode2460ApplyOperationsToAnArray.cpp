#include "LeetCode2460ApplyOperationsToAnArray.h"

std::vector<int> LeetCode2460ApplyOperationsToAnArray::applyOperations(std::vector<int>& nums)
{
    int length= static_cast<int>(nums.size());
    for (int i=0;i<length-1;i++)
    {
        if (nums[i]==0)
            continue;
        if (nums[i]!=nums[i+1])
            continue;
        nums[i]*=2;
        nums[i+1]=0;
        i++;
    }
    int notZeroPointer=0;
    for (int i=0;i<length;i++)
    {
        if (nums[i]!=0)
        {
            std::swap(nums[i],nums[notZeroPointer]);
            notZeroPointer++;
        }
    }
    return nums;
}
