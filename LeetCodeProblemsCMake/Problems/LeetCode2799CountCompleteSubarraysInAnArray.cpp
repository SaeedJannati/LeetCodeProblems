//
// Created by saeed on 4/24/25.
//

#include "LeetCode2799CountCompleteSubarraysInAnArray.h"

#include <iostream>
#include <unordered_set>
using namespace std;

int LeetCode2799CountCompleteSubarraysInAnArray::countCompleteSubarrays(vector<int> &nums) {
    unordered_set<int> set{};
    int length = static_cast<int>(nums.size());
    for (auto num: nums) {
        set.insert(num);
    }
    int distinctNumCount = static_cast<int>(set.size());
    int result = 0;
    for (int i = 0; i < length-distinctNumCount ; i++) {
        set.clear();
        for (int j = i; j < length; j++) {
            set.insert(nums[j]);
            if (set.size() < distinctNumCount)
                continue;
            result += length - j;
            break;
        }
    }
    return result;
}

void LeetCode2799CountCompleteSubarraysInAnArray::Run() {
    vector<int> nums{1, 3, 1, 2, 2};
    cout << countCompleteSubarrays(nums);
}
