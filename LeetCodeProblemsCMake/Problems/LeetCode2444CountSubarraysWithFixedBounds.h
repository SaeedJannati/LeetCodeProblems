//
// Created by saeed on 4/27/25.
//

#ifndef LEETCODE2444COUNTSUBARRAYSWITHFIXEDBOUNDS_H
#define LEETCODE2444COUNTSUBARRAYSWITHFIXEDBOUNDS_H
#include <vector>

#include "BaseProblem.h"


class LeetCode2444CountSubarraysWithFixedBounds: BaseProblem {
private:
    long long countSubarrays(std::vector<int>& nums, int minK, int maxK);
    public:
    void Run() override;
};



#endif //LEETCODE2444COUNTSUBARRAYSWITHFIXEDBOUNDS_H
