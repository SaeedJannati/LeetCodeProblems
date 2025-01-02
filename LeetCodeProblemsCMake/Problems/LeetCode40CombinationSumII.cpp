//
// Created by saeed on 1/2/25.
//

#include "LeetCode40CombinationSumII.h"

#include <algorithm>


std::vector<std::vector<int> > LeetCode40CombinationSumII::combinationSum2(std::vector<int> &candidates, int target) {
    std::vector<std::vector<int> > result;
    std::ranges::sort(candidates);
    int length = static_cast<int>(candidates.size());
    int last=-1;
    for (int i = 0; i < length; i++) {
        if (candidates[i] > target)
            break;
        if (candidates[i] == last) {
            last = candidates[i];
            continue;
        }
        last = candidates[i];
        Batcktrack(candidates, length, target, i, {candidates[i]}, result, candidates[i]);
    }
    return result;
}

void LeetCode40CombinationSumII::Batcktrack(std::vector<int> &candidates, int length, int target, int index,
                                            std::vector<int> nums,
                                            std::vector<std::vector<int> > &result, int sum) {
    if (sum == target) {
        result.push_back(nums);
        return;
    }
    int last = -1;
    for (int i = index + 1; i < length; i++) {
        if (sum + candidates[i] > target)
            return;
        if (candidates[i] ==last) {
            last = candidates[i];
            continue;
        }
        last = candidates[i];
        std::vector<int> newNums = nums;
        newNums.push_back(candidates[i]);
        Batcktrack(candidates, length, target, i, newNums, result, sum + candidates[i]);
    }
}

void LeetCode40CombinationSumII::Run() {
    std::vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    combinationSum2(candidates, target);
}
