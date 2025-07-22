#include "LeetCode1695MaximumErasureValue.h"

#include <algorithm>
#include <unordered_map>
using namespace std;

int LeetCode1695MaximumErasureValue::maximumUniqueSubarray(vector<int>& nums)
{
    int sum{};
    int maxSum{};
    unordered_map<int, int> map{};
    int firstPointer{};
    int secondPointer{};
    int length = nums.size();
    while (secondPointer < length)
    {
        if (!map.contains(nums[secondPointer]))
        {
            map[nums[secondPointer]]= secondPointer;
            sum+= nums[secondPointer];
            maxSum = std::max(sum, maxSum);
            secondPointer++;
            continue;
        }
        for (int i=firstPointer,e=map[nums[secondPointer]];i<=e;i++)
        {
            sum-= nums[i];
            map.erase(nums[i]);
            firstPointer++;
        }
        map[nums[secondPointer]]= secondPointer;
        sum+= nums[secondPointer];
        maxSum = std::max(sum, maxSum);
        secondPointer++;
    }
    return  maxSum;
}
