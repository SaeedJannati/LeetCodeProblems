//
// Created by saeed on 1/2/25.
//

#ifndef LEETCODE40COMBINATIONSUMII_H
#define LEETCODE40COMBINATIONSUMII_H
#include <vector>

#include "BaseProblem.h"


class LeetCode40CombinationSumII: BaseProblem {
    public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target);
    void Batcktrack(std::vector<int> &candidates, int length, int target, int index, std::vector<int> nums,
                std::vector<std::vector<int> >& result, int sum);
    void Run() override;
};



#endif //LEETCODE40COMBINATIONSUMII_H
