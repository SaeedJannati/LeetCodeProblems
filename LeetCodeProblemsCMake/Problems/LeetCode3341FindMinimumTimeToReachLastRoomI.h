//
// Created by saeed on 5/7/25.
//

#ifndef LEETCODE3341FINDMINIMUMTIMETOREACHLASTROOMI_H
#define LEETCODE3341FINDMINIMUMTIMETOREACHLASTROOMI_H
#include <vector>

#include "BaseProblem.h"


class LeetCode3341FindMinimumTimeToReachLastRoomI: BaseProblem {
    private:
    int minTimeToReach(std::vector<std::vector<int>>& moveTime);
public:
    void Run() override;
};



#endif //LEETCODE3341FINDMINIMUMTIMETOREACHLASTROOMI_H
