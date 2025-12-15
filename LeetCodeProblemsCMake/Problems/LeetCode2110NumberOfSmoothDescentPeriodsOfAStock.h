//
// Created by saeed on 12/15/25.
//

#ifndef LEETCODEPROBLEMSCMAKE_LEETCODE2110NUMBEROFSMOOTHDESCENTPERIODSOFASTOCK_H
#define LEETCODEPROBLEMSCMAKE_LEETCODE2110NUMBEROFSMOOTHDESCENTPERIODSOFASTOCK_H
#include <vector>

#include "BaseProblem.h"


class LeetCode2110NumberOfSmoothDescentPeriodsOfAStock: BaseProblem {
    long long getDescentPeriods(std::vector<int>& prices) ;
public:
    void Run() override;
};


#endif //LEETCODEPROBLEMSCMAKE_LEETCODE2110NUMBEROFSMOOTHDESCENTPERIODSOFASTOCK_H