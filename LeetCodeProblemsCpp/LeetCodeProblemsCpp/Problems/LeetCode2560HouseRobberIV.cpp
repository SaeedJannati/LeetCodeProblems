#include "LeetCode2560HouseRobberIV.h"

#include <algorithm>
#include <iostream>

int LeetCode2560HouseRobberIV::minCapability(std::vector<int>& nums, int k)
{
    int length = static_cast<int>(nums.size());
    int begin = std::numeric_limits<int>::max();
    int end = std::numeric_limits<int>::min();
    for (int i = 0; i < length; i++)
    {
        begin = std::min(nums[i], begin);
        end = std::max(nums[i], end);
    }
    int min = begin;
    int minChosen = std::numeric_limits<int>::max();
    int mid{};
    int lastChosenIndex{-2};
    int count{};
    int maxChosen = std::numeric_limits<int>::min();
    while (begin <= end)
    {
        mid = (end + begin) / 2;
        lastChosenIndex = -2;
        count = 0;
        maxChosen = std::numeric_limits<int>::min();
        for (int i = 0; i < length; i++)
        {
            if (nums[i] > mid)
                continue;
            if (i - lastChosenIndex == 1)
                continue;
            lastChosenIndex = i;
            maxChosen = std::max(nums[i], maxChosen);
            count++;
            if (count == k)
                break;
        }
        if (count < k)
        {
            begin = mid + 1;
            continue;
        }
        minChosen = std::min(maxChosen, minChosen);
        end = mid - 1;
    }
    if (minChosen >= min)
        return minChosen;
    return 0;
}

void LeetCode2560HouseRobberIV::Run()
{
    std::vector nums{2,3,5,9};
    constexpr int k = 2;
    std::cout << minCapability(nums, k) << std::endl;
}
