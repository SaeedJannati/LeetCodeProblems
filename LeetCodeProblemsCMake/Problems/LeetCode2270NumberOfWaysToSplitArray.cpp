//
// Created by saeed on 1/3/25.
//

#include "LeetCode2270NumberOfWaysToSplitArray.h"

#include <iostream>
# pragma  better solution
int LeetCode2270NumberOfWaysToSplitArray::waysToSplitArray(std::vector<int> &nums) {
    const int length = static_cast<int>(nums.size());
    long suffixSum = 0;
    long prefixSum = 0;
    for (int i = 0; i < length; i++) {
        suffixSum += nums[i];
    }
    int counter = 0;
    for (int i = 0; i < length-1; i++) {
        prefixSum += nums[i];
        suffixSum -= nums[i];
        if (prefixSum >= suffixSum)
            counter++;
    }
    return counter;
}

void LeetCode2270NumberOfWaysToSplitArray::Run() {
    std::vector<int> nums{10, 4, -8, 7};
    std::cout << waysToSplitArray(nums);
}
#pragma  endregion
#pragma region prefix suffix array
// int LeetCode2270NumberOfWaysToSplitArray::waysToSplitArray(std::vector<int> &nums) {
//     int length = nums.size();
//     std::vector<long> prefixSum(length, 0);
//     std::vector<long> suffixSum(length, 0);
//     prefixSum[0] = nums[0];
//     suffixSum[length - 1] = 0;
//     for (int i = 1; i < length; i++) {
//         prefixSum[i] = prefixSum[i - 1] + nums[i];
//     }
//     for (int i = length - 2; i >= 0; i--) {
//         suffixSum[i] = suffixSum[i + 1] + nums[i + 1];
//     }
//     int counter = 0;
//     for (int i = 0; i < length - 1; i++) {
//         if (prefixSum[i] >= suffixSum[i])
//             counter++;
//     }
//     return counter;
// }
#pragma endregion
