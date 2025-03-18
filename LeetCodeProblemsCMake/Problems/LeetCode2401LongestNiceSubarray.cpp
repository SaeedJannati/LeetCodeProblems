//
// Created by saeed on 3/18/25.
//

#include "LeetCode2401LongestNiceSubarray.h"

#include <iostream>
#include <limits>
#include <ostream>
using namespace std;

int LeetCode2401LongestNiceSubarray::longestNiceSubarray(vector<int> &nums) {
    int length = static_cast<int>(nums.size());
    if (length == 1)
        return 1;
    int maxLength = 1;
    int secondPointer = 1;
    int currentLength{};
    bool foundContradiction = false;
    for (int i = 0; i < length; i++) {
        foundContradiction = false;
        secondPointer = i+1;
        while (secondPointer < length) {
            for (int j = i; j < secondPointer; j++) {
                if ((nums[j] & nums[secondPointer]) == 0)
                    continue;
                foundContradiction = true;
                currentLength=secondPointer-i;
                if (currentLength > maxLength) {
                    maxLength = currentLength;
                }
                break;
            }
            if (!foundContradiction) {
                secondPointer++;
                continue;
            }
            break;
        }
        if (!foundContradiction) {
            currentLength=secondPointer-i;
            if (currentLength > maxLength) {
                maxLength = currentLength;
            }
        }
    }
    return maxLength;
}

void LeetCode2401LongestNiceSubarray::Run() {
    vector<int> nums={135745088,609245787,16,2048,2097152};
    cout<<longestNiceSubarray(nums)<<endl;
}
