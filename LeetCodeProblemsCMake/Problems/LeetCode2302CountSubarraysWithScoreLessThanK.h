//
// Created by saeed on 4/28/25.
//

#ifndef LEETCODE2302COUNTSUBARRAYSWITHSCORELESSTHANK_H
#define LEETCODE2302COUNTSUBARRAYSWITHSCORELESSTHANK_H
#include <vector>

#include "BaseProblem.h"


class LeetCode2302CountSubarraysWithScoreLessThanK: BaseProblem {
    private:
    long long countSubarrays(std::vector<int>& nums, long long k);
    public:
    void Run() override;
};



#endif //LEETCODE2302COUNTSUBARRAYSWITHSCORELESSTHANK_H
