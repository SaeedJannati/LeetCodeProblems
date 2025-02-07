//
// Created by saeed on 2/7/25.
//

#ifndef LEETCODE3160FINDTHENUMBEROFDISTINCTCOLORSAMONGTHEBALLS_H
#define LEETCODE3160FINDTHENUMBEROFDISTINCTCOLORSAMONGTHEBALLS_H
#include <vector>

#include "BaseProblem.h"


class LeetCode3160FindTheNumberOfDistinctColorsAmongTheBalls: BaseProblem {
    std::vector<int> queryResults(int limit, std::vector<std::vector<int>>& queries);
public:
    void Run() override;
};



#endif //LEETCODE3160FINDTHENUMBEROFDISTINCTCOLORSAMONGTHEBALLS_H
