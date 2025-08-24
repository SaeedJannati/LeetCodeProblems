//
// Created by saeed on 8/24/25.
//

#include "LeetCode1493LongestSubarrayOf1sAfterDeletingOneElement.h"
using namespace std;
int LeetCode1493LongestSubarrayOf1sAfterDeletingOneElement::longestSubarray( vector<int> &nums) {
    int zeroIndex{-1};
    int maxLength{0};
    int currentLength{0};
    int firstPointer{0};
    int length=static_cast<int>(nums.size());
    for (int i=0;i<length;i++) {
        if (nums[i] == 0) {
            if (zeroIndex==-1) {
                zeroIndex = i;
                continue;
            }
            currentLength=i-firstPointer-1;
            if (currentLength > maxLength) {
                maxLength = currentLength;
            }
            firstPointer = zeroIndex+1;
            zeroIndex=i;
        }
    }
    currentLength=length-firstPointer-1;
    if (currentLength > maxLength) {
        maxLength = currentLength;
    }
    return maxLength;
}
