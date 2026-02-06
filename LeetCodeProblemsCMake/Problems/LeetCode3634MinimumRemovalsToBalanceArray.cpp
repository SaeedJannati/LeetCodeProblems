//
// Created by saeed on 2/6/26.
//

#include "LeetCode3634MinimumRemovalsToBalanceArray.h"

#include <algorithm>
using namespace std;

int LeetCode3634MinimumRemovalsToBalanceArray::minRemoval(vector<int> &nums, int k) {
    ranges::sort(nums);
    int secondPointer{0};
    int currentLength{0};
    long maxAllowed{0};
    int maxLength{1};
    int length = static_cast<int>(nums.size());
    for (int i = 0; i < length - 1; ++i) {
        maxAllowed = k;
        maxAllowed*= nums[i];
        while (secondPointer < length - 1 && nums[secondPointer] <= maxAllowed) {
            secondPointer++;
        }
        currentLength = secondPointer - i + 1;
        if (nums[secondPointer] > maxAllowed) {
            --currentLength;
        }
        maxLength = max(maxLength, currentLength);
    }
    return length - maxLength;
}
