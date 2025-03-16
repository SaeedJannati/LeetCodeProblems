#include "LeetCode90SubsetsII.h"

#include <algorithm>

#include "Auxilaries.h"
using namespace std;

void BackTrack(vector<vector<int>>& result, vector<int>& nums, vector<int>& current, int index, int numLength)
{
    if (index == numLength)
        return;
    int lastNum{-11};
    for (int i = index + 1; i < numLength; i++)
    {
        if (nums[i] == lastNum)
            continue;
        current.push_back(nums[i]);
        lastNum = nums[i];
        result.emplace_back(current);
        BackTrack(result, nums, current, i, numLength);
        current.pop_back();
    }
}

vector<vector<int>> LeetCode90SubsetsII::subsetsWithDup(vector<int>& nums)
{
    vector<vector<int>> result{};
    ranges::sort(nums);
    result.push_back({});
    int length = static_cast<int>(nums.size());
    vector<int> current{};
    BackTrack(result, nums, current, -1, length);
    return result;
}

void LeetCode90SubsetsII::Run()
{
    vector<int> nums{4,4,4,1,4};
    auto result = subsetsWithDup(nums);
    Auxilaries::PrintVector(result);
}
