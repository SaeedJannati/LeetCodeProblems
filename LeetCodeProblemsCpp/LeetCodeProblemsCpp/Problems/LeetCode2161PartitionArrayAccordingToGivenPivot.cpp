#include "LeetCode2161PartitionArrayAccordingToGivenPivot.h"

std::vector<int> LeetCode2161PartitionArrayAccordingToGivenPivot::pivotArray(std::vector<int>& nums, int pivot)
{
    int length=static_cast<int>(nums.size());
    std::vector<int> less{};
    less.reserve(length);
    std::vector<int> greater{};
    greater.reserve(length);
    std::vector<int> equal{};
    for (int i=0;i<length;i++)
    {
        if (nums[i]>pivot)
            greater.push_back(nums[i]);
        else if(nums[i]==pivot)
            equal.push_back(nums[i]);
        else
            less.push_back(nums[i]);
    }
    int lessLength=static_cast<int>( less.size());
    int greaterLength=static_cast<int>( greater.size());
    int equalLength=static_cast<int>( equal.size());
    for (int i=0;i<lessLength;i++)
    {
        nums[i]=less[i];
    }
    for (int i=0;i<equalLength;i++)
    {
        nums[i+lessLength]=pivot;
    }
    for (int i=0;i<greaterLength;i++)
    {
        nums[i+lessLength+equalLength]=greater[i];
    }
    return nums;
}
