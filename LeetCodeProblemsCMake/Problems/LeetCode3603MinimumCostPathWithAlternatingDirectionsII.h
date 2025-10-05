//
// Created by saeed on 10/5/25.
//

#ifndef LEETCODEPROBLEMSCMAKE_LEETCODE3603MINIMUMCOSTPATHWITHALTERNATINGDIRECTIONSII_H
#define LEETCODEPROBLEMSCMAKE_LEETCODE3603MINIMUMCOSTPATHWITHALTERNATINGDIRECTIONSII_H
#include <vector>

#include "BaseProblem.h"


class LeetCode3603MinimumCostPathWithAlternatingDirectionsII: BaseProblem {
private:
    long long minCost(int m, int n, std::vector<std::vector<int>>& waitCost);
    public:
    void Run() override;
};


#endif //LEETCODEPROBLEMSCMAKE_LEETCODE3603MINIMUMCOSTPATHWITHALTERNATINGDIRECTIONSII_H