//
// Created by Saeed Jannati on 5/10/2026 A.
//

#include "LeetCode2770MaximumNumberOfJumpsToReachTheLastIndex.h"

#include <math.h>
using namespace std;

int LeetCode2770MaximumNumberOfJumpsToReachTheLastIndex::maximumJumps(vector<int> &nums, int target) {
    int length = static_cast<int>(nums.size());
    vector<int> dp(length, -1);
    dp[0] = 0;
    for (int i = 1; i < length; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] == -1)
                continue;
            if (abs(nums[i] - nums[j]) > target)
                continue;
            dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    return dp[length - 1];
}
