//
// Created by saeed on 11/12/25.
//

#include "LeetCode2654MinimumNumberOfOperationsToMakeAllArrayElementsEqualTo1.h"

#include <iostream>
using namespace std;

int findGcd(int a, int b) {
    if (a % b == 0) return b;
    return findGcd(b, a % b);
}

int calcGcd(vector<int> &nums, int start, int end) {
    if (start == end)
        return nums[start];
    if (start - end == 1) {
        return findGcd(nums[start], nums[end]);
    }
    int mid = (start + end) >> 1;
    int leftGcd = calcGcd(nums, start, mid);
    int rightGcd = calcGcd(nums, mid + 1, end);
    return findGcd(leftGcd, rightGcd);
}

int LeetCode2654MinimumNumberOfOperationsToMakeAllArrayElementsEqualTo1::minOperations(vector<int> &nums) {
    int length = static_cast<int>(nums.size());
    int noneOneLength=length;
    for (int i=0;i<length;i++) {
        if (nums[i]==1)
            --noneOneLength;
    }
    if (noneOneLength!=length) {
        return noneOneLength;
    }
    for (int i=0;i<length;i++) {
        for (int j=0;j<length-i;j++) {
            if (calcGcd(nums,j,i+j)==1) {
                return length+i-1;
            }
        }
    }
    return -1;
}

void LeetCode2654MinimumNumberOfOperationsToMakeAllArrayElementsEqualTo1::Run() {
    vector<int> nums = {2, 6, 3, 4};
    cout << minOperations(nums) << '\n';
}
