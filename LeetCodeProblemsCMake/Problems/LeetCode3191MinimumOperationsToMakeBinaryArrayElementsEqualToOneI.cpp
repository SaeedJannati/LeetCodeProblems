//
// Created by saeed on 3/19/25.
//

#include "LeetCode3191MinimumOperationsToMakeBinaryArrayElementsEqualToOneI.h"

int LeetCode3191MinimumOperationsToMakeBinaryArrayElementsEqualToOneI::minOperations(std::vector<int> &nums) {
    int length = static_cast<int>( nums.size());
    int operationCount{};
    for (int i = 0; i < length-2; i++) {
        if (nums[i] == 0) {
            operationCount++;
            nums[i] = 1;
            nums[i+1]=nums[i+1]==1?0:1;
            nums[i+2]=nums[i+2]==1?0:1;
        }
    }
    if ( nums[length-2]==0||nums[length-1]==0)
        return -1;
    return operationCount;
}
