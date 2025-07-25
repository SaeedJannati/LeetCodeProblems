//
// Created by saeed on 7/25/25.
//

#include "LeetCode3487MaximumUniqueSubarraySumAfterDeletion.h"

#include <unordered_map>
#include <unordered_set>
using namespace std;
int LeetCode3487MaximumUniqueSubarraySumAfterDeletion::maxSum(vector<int> &nums) {
    unordered_set< int> positiveNums{};
    int sum{};
    int maxNums{-101};
    for(int num:nums) {
        if (num > maxNums) {
            maxNums = num;
        }
        if (num<=0)
            continue;
        if (positiveNums.contains(num)) {
            continue;
        }
        positiveNums.insert(num);
        sum+=num;
    }
    if (maxNums <= 0)
        return maxNums;
    return sum;
}
