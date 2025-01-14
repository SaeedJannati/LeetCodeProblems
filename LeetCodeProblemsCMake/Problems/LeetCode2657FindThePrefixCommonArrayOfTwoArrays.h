//
// Created by saeed on 1/14/25.
//

#ifndef LEETCODE2657FINDTHEPREFIXCOMMONARRAYOFTWOARRAYS_H
#define LEETCODE2657FINDTHEPREFIXCOMMONARRAYOFTWOARRAYS_H
#include <vector>

#include "BaseProblem.h"


class LeetCode2657FindThePrefixCommonArrayOfTwoArrays: BaseProblem {
private:
    std::vector<int> findThePrefixCommonArray(std::vector<int>& A, std::vector<int>& B);
    public:
    void Run() override;
};



#endif //LEETCODE2657FINDTHEPREFIXCOMMONARRAYOFTWOARRAYS_H
