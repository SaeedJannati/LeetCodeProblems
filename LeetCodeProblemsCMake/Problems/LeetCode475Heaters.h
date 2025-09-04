//
// Created by saeed on 9/4/25.
//

#ifndef LEETCODEPROBLEMSCMAKE_LEETCODE475HEATERS_H
#define LEETCODEPROBLEMSCMAKE_LEETCODE475HEATERS_H
#include <vector>

#include "BaseProblem.h"


class LeetCode475Heaters: BaseProblem{
    int findRadius(std::vector<int>& houses, std::vector<int>& heaters);
    public:
    void Run() override;
};


#endif //LEETCODEPROBLEMSCMAKE_LEETCODE475HEATERS_H