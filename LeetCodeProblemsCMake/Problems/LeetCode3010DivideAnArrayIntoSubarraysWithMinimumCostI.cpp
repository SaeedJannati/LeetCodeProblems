//
// Created by Saeed Jannati on 2/1/2026 A.
//

#include "LeetCode3010DivideAnArrayIntoSubarraysWithMinimumCostI.h"

#include <algorithm>
using namespace std;

int LeetCode3010DivideAnArrayIntoSubarraysWithMinimumCostI::minimumCost(vector<int> &nums) {
    int firstNum{nums[0]};
    ranges::sort(nums);
    if (nums[2]<firstNum) {
        nums[2]=firstNum;
    }
    return nums[0]+nums[1]+nums[2];
}
