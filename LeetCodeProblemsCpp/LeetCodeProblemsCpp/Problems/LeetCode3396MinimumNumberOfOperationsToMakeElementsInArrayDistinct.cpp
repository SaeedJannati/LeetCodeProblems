#include "LeetCode3396MinimumNumberOfOperationsToMakeElementsInArrayDistinct.h"

#include <iostream>
#include <ostream>
#include <unordered_set>

using  namespace  std;
int LeetCode3396MinimumNumberOfOperationsToMakeElementsInArrayDistinct::minimumOperations(vector<int>& nums)
{
    unordered_set<int> distinctNums;
    int length=static_cast<int>(nums.size());
    for (int i=length-1;i>=0;i--)
    {
                if (distinctNums.contains(nums[i]))
                {
                    return i/3+(i%3==0?0:1);
                }
        distinctNums.insert(nums[i]);
    }
    return 0;
}

void LeetCode3396MinimumNumberOfOperationsToMakeElementsInArrayDistinct::Run()
{
    vector<int> nums{1,2,3,4,2,3,3,5,7};
    cout<<minimumOperations(nums)<<endl;
}
