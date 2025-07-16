#include "LeetCode3201FindTheMaximumLengthOfValidSubsequenceI.h"

#include <algorithm>
#include <iostream>
#include <ostream>
using namespace std;

int LeetCode3201FindTheMaximumLengthOfValidSubsequenceI::maximumLength(vector<int>& nums)
{
    int oddCount{};
    int evenCount{};
    int length = nums.size();
    int firstOddIndex = length;
    int firstEvenIndex = length;
    for (int i = 0; i < length; i++)
    {
        if (nums[i] % 2 == 1)
        {
            oddCount++;
            if (firstOddIndex == length)
                firstOddIndex = i;
            continue;
        }
        evenCount++;
        if (firstEvenIndex == length)
            firstEvenIndex = i;
    }
    int result = max(oddCount, evenCount);
    int alternateLength = 1;
    int modulo=nums[0]%2==1?0:1;
    for (int i = 1; i <length; i++)
    {
        if (nums[i] % 2 == modulo)
        {
            alternateLength++;
            modulo = modulo==1?0:1;
        }
    }
    result = std::max(alternateLength, result);
    return result;
}

void LeetCode3201FindTheMaximumLengthOfValidSubsequenceI::Run()
{
    vector<int> nums={1,2,3,4};
    cout<<maximumLength(nums)<<endl;
}
