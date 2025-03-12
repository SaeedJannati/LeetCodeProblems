#include "LeetCode2529MaximumCountOfPositiveIntegerAndNegativeInteger.h"

#include <iostream>
#include <ostream>
#pragma region O(logN) TC
int LeetCode2529MaximumCountOfPositiveIntegerAndNegativeInteger::maximumCount(std::vector<int>& nums)
{
    int length = static_cast<int>(nums.size());
    if (nums[0] > 0 || nums[length - 1] < 0)
        return length;
    int begin = 0;
    int end = length - 1;
    int mid{};
    int next{};
    while (begin <= end)
    {
        mid = (begin + end) / 2;
        next = std::min(mid + 1, length - 1);
        if (nums[mid] < 0 && nums[next] > 0)
            break;
        if (nums[mid] >= 0)
            end = mid - 1;
        else
            begin = mid + 1;
    }
    int negCount{};
    if (nums[mid] >= 0)
        negCount = mid;
    else
        negCount = mid + 1;

    begin = 0;
    end = length - 1;
    int before{};
    while (begin <= end)
    {
        mid = (begin + end) / 2;
        before = std::max(mid - 1, 0);
        if (nums[mid] > 0 && nums[before] <0)
            break;
        if (nums[mid] <= 0)
            begin = mid + 1;
        else
            end = mid - 1;
    }
    int posCount{};
    if (nums[mid] <= 0)
        posCount = length - mid-1;
    else
        posCount = length - mid;
    return std::ranges::max(posCount, negCount);
}

void LeetCode2529MaximumCountOfPositiveIntegerAndNegativeInteger::Run()
{
    std::vector<int> nums{-3, -2, -1, 0, 0, 1, 2};
    std::cout << maximumCount(nums) << std::endl;
}
#pragma endregion
#pragma region O(n) TC
// int LeetCode2529MaximumCountOfPositiveIntegerAndNegativeInteger::maximumCount(std::vector<int>& nums)
// {
//     int negCount {};
//     int posCount {};
//     for (auto num : nums)
//     {
//         if (num > 0)
//             posCount++;
//         if (num < 0)
//             negCount++;
//     }
//     return std::max(posCount, negCount);
// }
#pragma endregion
