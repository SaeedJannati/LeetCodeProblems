//
// Created by saeed on 4/19/25.
//

#ifndef LEETCODE2563COUNTTHENUMBEROFFAIRPAIRS_H
#define LEETCODE2563COUNTTHENUMBEROFFAIRPAIRS_H
#include <vector>

#include "BaseProblem.h"


class LeetCode2563CountTheNumberOfFairPairs: BaseProblem {
    private:
    long long countFairPairs(std::vector<int>& nums, int lower, int upper);
    public:
    void Run() override;
};



#endif //LEETCODE2563COUNTTHENUMBEROFFAIRPAIRS_H
