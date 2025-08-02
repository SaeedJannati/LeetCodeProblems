//
// Created by saeed on 8/2/25.
//

#ifndef LEETCODE2561REARRANGINGFRUITS_H
#define LEETCODE2561REARRANGINGFRUITS_H
#include <vector>

#include "BaseProblem.h"


class LeetCode2561RearrangingFruits: BaseProblem {
private:
    long long minCost(std::vector<int>& basket1, std::vector<int>& basket2);
    public:
    void Run() override;
};



#endif //LEETCODE2561REARRANGINGFRUITS_H
