//
// Created by saeed on 10/18/25.
//

#include "LeetCode3397MaximumNumberOfDistinctElementsAfterOperations.h"

#include <algorithm>
#include <unordered_set>
using namespace std;

int LeetCode3397MaximumNumberOfDistinctElementsAfterOperations::maxDistinctElements(vector<int> &nums, int k) {
    ranges::sort(nums);
    int length = static_cast<int>(nums.size());
    unordered_set<int> set{};
    nums[0] -= k;
    set.insert(nums[0]);
    for (int i = 1; i < length; i++) {
        if (nums[i-1]<nums[i]) {
            nums[i] = nums[i] - nums[i - 1] - 1<=k?nums[i-1]+1:nums[i]-k;
        }
        else {
            nums[i]=nums[i-1]+1-nums[i]<=k?nums[i-1]+1:nums[i]+k;
        }
        set.insert(nums[i]);

    }
    return set.size();
}
