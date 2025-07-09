//
// Created by saeed on 4/24/25.
//

#ifndef LEETCODE2799COUNTCOMPLETESUBARRAYSINANARRAY_H
#define LEETCODE2799COUNTCOMPLETESUBARRAYSINANARRAY_H
#include <vector>

#include "BaseProblem.h"


class LeetCode2799CountCompleteSubarraysInAnArray: BaseProblem {
    private:
    int countCompleteSubarrays(std::vector<int>& nums);
    public:
    void Run() override;
};



#endif //LEETCODE2799COUNTCOMPLETESUBARRAYSINANARRAY_H
