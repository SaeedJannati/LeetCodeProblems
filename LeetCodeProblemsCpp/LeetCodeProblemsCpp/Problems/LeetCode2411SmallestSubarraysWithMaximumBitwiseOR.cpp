#include "LeetCode2411SmallestSubarraysWithMaximumBitwiseOR.h"

#include <algorithm>
#include <unordered_map>

#include "Auxilaries.h"
using namespace std;

vector<int> LeetCode2411SmallestSubarraysWithMaximumBitwiseOR::smallestSubarrays(vector<int>& nums)
{
    vector<int> lastSeen(32, -1);
    int length = nums.size();
    vector<int> result(length, 1);
    for (int i = length - 1; i >= 0; i--)
    {
        for (int j = 0; j < 32; j++)
        {
            if ((nums[i] >> j & 1) == 1)
            {
                lastSeen[j] = i;
            }
        }
        int maxIndex=i;
        for (int j = 0; j < 32; j++)
        {
            if (lastSeen[j] != -1)
                maxIndex = max(maxIndex, lastSeen[j]);
        }
        result[i] = maxIndex - i + 1;
    }
    return result;
}

void LeetCode2411SmallestSubarraysWithMaximumBitwiseOR::Run()
{
    vector<int> nums =
        // {1,2};
        {1, 0, 2, 1, 3};
    auto res = smallestSubarrays(nums);
    Auxilaries::PrintVector(res);
}
