#include "LeetCode215FindKthElement.h"

#include <queue>

void LeetCode215FindKthElement::Run()
{

    
}
int LeetCode215FindKthElement::findKthLargest(std::vector<int>& nums, int k)
{
    auto size=static_cast<int>(nums.size());
    std::priority_queue<int, std::vector<int>, std::less<>> maxHeap;
    for(int i=0;i<size;i++)
    {
        maxHeap.push(nums[i]);
    }
    for(int i=0;i<k-1;i++)
        maxHeap.pop();
    return maxHeap.top();
}


