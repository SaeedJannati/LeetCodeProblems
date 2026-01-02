//
// Created by saeed on 1/2/26.
//

#include "LeetCode961NRepeatedElementInSize2NArray.h"

int LeetCode961NRepeatedElementInSize2NArray::repeatedNTimes(std::vector<int> &nums) {
    int length= static_cast<int>(nums.size());
    if (nums[0]==nums[1]|| nums[0]==nums[2]) {
        return nums[0];
    }
    if (nums[1]==nums[2]) {
        return  nums[1];
    }
    int candidate{};
    int count{};
    for (int i=3;i<length;++i) {
        if (count==0) {
            candidate=nums[i];
            ++count;
            continue;
        }
        if (candidate==nums[i]) {
            ++count;
            continue;
        }
        --count;
    }
    return candidate;
}
