//
// Created by saeed on 4/25/25.
//

#ifndef LEETCODE2845COUNTOFINTERESTINGSUBARRAYS_H
#define LEETCODE2845COUNTOFINTERESTINGSUBARRAYS_H
#include <vector>

#include "BaseProblem.h"


class LeetCode2845CountOfInterestingSubarrays: BaseProblem {
    private:
    long long countInterestingSubarrays(std::vector<int>& nums, int modulo, int k) ;
    public:
    void Run() override;
};



#endif //LEETCODE2845COUNTOFINTERESTINGSUBARRAYS_H
