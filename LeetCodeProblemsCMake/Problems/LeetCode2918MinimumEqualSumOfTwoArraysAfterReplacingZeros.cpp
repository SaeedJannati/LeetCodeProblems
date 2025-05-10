//
// Created by saeed on 5/10/25.
//

#include "LeetCode2918MinimumEqualSumOfTwoArraysAfterReplacingZeros.h"
using namespace std;

long long LeetCode2918MinimumEqualSumOfTwoArraysAfterReplacingZeros::minSum(vector<int> &nums1, vector<int> &nums2) {
    int firstZeroCount{};
    long long firstSum{};
    const int firstLength = static_cast<int>(nums1.size());
    int secondZeroCount{};
    long long secondSum{};
    const int secondLength = static_cast<int>(nums2.size());
    for (int i = 0; i < firstLength; i++) {
        if (nums1[i] == 0) {
            firstZeroCount++;
            continue;
        }
        firstSum += nums1[i];
    }
    for (int i = 0; i < secondLength; i++) {
        if (nums2[i] == 0) {
            secondZeroCount++;
        }
        secondSum += nums2[i];
    }
    firstSum+=firstZeroCount;
    secondSum+=secondZeroCount;
    if (firstZeroCount==0) {
        if (firstSum<secondSum) {
            return -1;
        }
    }
    if (secondZeroCount==0) {
        if (secondSum<firstSum) {
            return -1;
        }
    }
    return max(firstSum, secondSum);
}
