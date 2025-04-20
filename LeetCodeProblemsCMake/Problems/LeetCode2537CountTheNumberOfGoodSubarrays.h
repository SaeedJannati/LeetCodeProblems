//
// Created by saeed on 4/17/25.
//

#ifndef LEETCODE2537COUNTTHENUMBEROFGOODSUBARRAYS_H
#define LEETCODE2537COUNTTHENUMBEROFGOODSUBARRAYS_H
#include <vector>

#include "BaseProblem.h"


class LeetCode2537CountTheNumberOfGoodSubarrays: BaseProblem {
    private:
    long long countGood(std::vector<int>& nums, int k);
    public:
    void Run() override;
};



#endif //LEETCODE2537COUNTTHENUMBEROFGOODSUBARRAYS_H
