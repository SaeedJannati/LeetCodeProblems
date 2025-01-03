//
// Created by saeed on 1/3/25.
//

#include "LeetCode2270NumberOfWaysToSplitArray.h"

int LeetCode2270NumberOfWaysToSplitArray::waysToSplitArray(std::vector<int> &nums) {
    int length = nums.size();
    std::vector<long> prefixSum(length, 0);
    std::vector<long> suffixSum(length, 0);
    prefixSum[0] = nums[0];
    suffixSum[length - 1] = 0;
    for (int i = 1; i < length; i++) {
        prefixSum[i] = prefixSum[i - 1] + nums[i];
    }
    for (int i = length - 2; i >= 0; i--) {
        suffixSum[i] = suffixSum[i + 1] + nums[i + 1];
    }
    int counter = 0;
    for (int i = 0; i < length - 1; i++) {
        if (prefixSum[i] >= suffixSum[i])
            counter++;
    }
    return counter;
}
