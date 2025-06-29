//
// Created by saeed on 6/29/25.
//

#ifndef LEETCODE1498NUMBEROFSUBSEQUENCESTHATSATISFYTHEGIVENSUMCONDITION_H
#define LEETCODE1498NUMBEROFSUBSEQUENCESTHATSATISFYTHEGIVENSUMCONDITION_H
#include <vector>

#include "BaseProblem.h"


class LeetCode1498NumberOfSubsequencesThatSatisfyTheGivenSumCondition: BaseProblem {
private:
    int numSubseq(std::vector<int>& nums, int target);
public:
    void Run() override;
};



#endif //LEETCODE1498NUMBEROFSUBSEQUENCESTHATSATISFYTHEGIVENSUMCONDITION_H
