//
// Created by saeed on 1/16/25.
//

#include "LeetCode2425BitwiseXOROfAllPairings.h"

int LeetCode2425BitwiseXOROfAllPairings::xorAllNums(std::vector<int> &nums1, std::vector<int> &nums2) {
    int sizeFirst = static_cast<int>(nums1.size());
    int sizeSecond = static_cast<int>(nums2.size());
    if (sizeFirst % 2 == 0 && sizeSecond % 2 == 0)
        return 0;
    int firstXor{};
    int secondXor{};
    if (sizeFirst % 2 == 1) {
        for (int i = 0; i < sizeSecond; i++) {
            secondXor ^= nums2[i];
        }
    }
    if (sizeSecond % 2 == 1) {
        for (int i = 0; i < sizeFirst; i++) {
            firstXor ^= nums1[i];
        }
    }
    return firstXor ^ secondXor;
}
