//
// Created by saeed on 5/19/25.
//

#include "LeetCode3024TypeOfTriangle.h"

#include <algorithm>
using namespace std;
string LeetCode3024TypeOfTriangle::triangleType(vector<int> &nums) {
    ranges::sort(nums);
    if (nums[0]+nums[1]<=nums[2])
        return "none";
    if (nums[0]==nums[1] && nums[1]==nums[2])
        return "equilateral";
    if (nums[0]==nums[2] || nums[2]==nums[1]||nums[1]==nums[0])
        return "isosceles";
    return "scalene";
}
