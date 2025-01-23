//
// Created by saeed on 1/23/25.
//

#ifndef LEETCODE174DUNGEONGAME_H
#define LEETCODE174DUNGEONGAME_H
#include <vector>

#include "BaseProblem.h"


class LeetCode174DungeonGame: BaseProblem {
    private:
    int calculateMinimumHP(std::vector<std::vector<int>>& dungeon);
public:
    void Run() override;
};



#endif //LEETCODE174DUNGEONGAME_H
