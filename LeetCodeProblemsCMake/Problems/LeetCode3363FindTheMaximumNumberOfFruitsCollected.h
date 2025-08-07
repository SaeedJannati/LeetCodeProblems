//
// Created by saeed on 8/7/25.
//

#ifndef LEETCODE3363FINDTHEMAXIMUMNUMBEROFFRUITSCOLLECTED_H
#define LEETCODE3363FINDTHEMAXIMUMNUMBEROFFRUITSCOLLECTED_H
#include <vector>

#include "BaseProblem.h"


class LeetCode3363FindTheMaximumNumberOfFruitsCollected: BaseProblem {
    private:
    int maxCollectedFruits(std::vector<std::vector<int>>& fruits);
    public:
    void Run() override;
};



#endif //LEETCODE3363FINDTHEMAXIMUMNUMBEROFFRUITSCOLLECTED_H
