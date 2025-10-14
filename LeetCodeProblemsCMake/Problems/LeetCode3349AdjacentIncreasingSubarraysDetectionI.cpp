//
// Created by saeed on 10/14/25.
//

#include "LeetCode3349AdjacentIncreasingSubarraysDetectionI.h"

#include <iostream>
using namespace std;

bool LeetCode3349AdjacentIncreasingSubarraysDetectionI::hasIncreasingSubarrays(vector<int> &nums, int k) {
    int currentStreak{1};
    int previousStreak{1};
    int length = static_cast<int>(nums.size());
    for (int i=1;i<length;i++) {
        if (nums[i]<=nums[i-1]) {
            if (currentStreak>=k) {
                if (previousStreak>=k)
                    return true;
            }
            if (currentStreak>=2*k) {
                return true;
            }
            previousStreak = currentStreak;
            currentStreak=1;
            continue;
        }
        currentStreak++;
    }
    if (currentStreak>=k) {
        if (previousStreak>=k)
            return true;
    }
    if (currentStreak>=2*k) {
        return true;
    }
    return false;
}

void LeetCode3349AdjacentIncreasingSubarraysDetectionI::Run() {
    vector<int> nums{2,5,7,8,9,2,3,4,3,1};
    int k=3;
    cout<<hasIncreasingSubarrays(nums, 5);
}
