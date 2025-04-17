//
// Created by saeed on 4/17/25.
//

#include "LeetCode2176CountEqualAndDivisiblePairsInAnArray.h"

int LeetCode2176CountEqualAndDivisiblePairsInAnArray::countPairs(std::vector<int> &nums, int k) {
    int length = static_cast<int>(nums.size());
    int result = 0;
    for (int i = 0; i < length-1; i++) {
        for (int j = i+1; j < length; j++) {
            if (nums[i] != nums[j])
                continue;
            if ((i*j)%k!=0)
                continue;
            result ++;
        }
    }
    return result;
}
