//
// Created by saeed on 9/23/25.
//

#ifndef LEETCODE1774CLOSESTDESSERTCOST_H
#define LEETCODE1774CLOSESTDESSERTCOST_H
#include <vector>

#include "BaseProblem.h"


class LeetCode1774ClosestDessertCost: BaseProblem {
private:


    int closestCost(std::vector<int>& baseCosts, std::vector<int>& toppingCosts, int target) ;
public:
    void Run() override;
};



#endif //LEETCODE1774CLOSESTDESSERTCOST_H
