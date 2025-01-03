//
// Created by saeed on 1/3/25.
//

#ifndef LEETCODE47PERMUTATIONSII_H
#define LEETCODE47PERMUTATIONSII_H
#include <vector>

#include "BaseProblem.h"


class LeetCode47PermutationsII: BaseProblem {
    public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums);

    void Backtrack(std::vector<int> &nums, std::vector<std::vector<int>> &result,
                   std::vector<int> &permutation,
                   int numsLength, int currentLength, std::vector<bool> &visited);
    void Run() override;
};



#endif //LEETCODE47PERMUTATIONSII_H
