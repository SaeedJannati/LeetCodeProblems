#include "LeetCode2570MergeTwo2DArraysBySummingValues.h"

std::vector<std::vector<int>> LeetCode2570MergeTwo2DArraysBySummingValues::mergeArrays(std::vector<std::vector<int>>& nums1, std::vector<std::vector<int>>& nums2)
{
    std::vector<std::vector<int>> res{};
    int firstLength = nums1.size();
    int secondLength = nums2.size();
    int firstPointer=0;
    int secondPointer=0;
    while (firstPointer < firstLength || secondPointer < secondLength)
    {
        if (firstPointer<firstLength && secondPointer<secondLength)
        {
            if (nums1[firstPointer][0]==nums2[secondPointer][0])
            {
                res.push_back({nums1[firstPointer][0],nums1[firstPointer][1]+nums2[secondPointer][1]});
                firstPointer++;
                secondPointer++;
                continue;
            }
            if (nums1[firstPointer][0]<nums2[secondPointer][0])
            {
                res.push_back({nums1[firstPointer][0],nums1[firstPointer][1]});
                firstPointer++;
                continue;
            }
            res.push_back({nums2[secondPointer][0],nums2[secondPointer][1]});
            secondPointer++;
            continue;
        }
        if (firstPointer<firstLength )
        {
            res.push_back({nums1[firstPointer][0],nums1[firstPointer][1]});
            firstPointer++;
            continue;
        }
        res.push_back({nums2[secondPointer][0],nums2[secondPointer][1]});
        secondPointer++;
        continue;
    }
    return res;
}
