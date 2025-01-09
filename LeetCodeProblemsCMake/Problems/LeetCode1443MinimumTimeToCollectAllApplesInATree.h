//
// Created by saeed on 1/9/25.
//

#ifndef LEETCODE1443MINIMUMTIMETOCOLLECTALLAPPLESINATREE_H
#define LEETCODE1443MINIMUMTIMETOCOLLECTALLAPPLESINATREE_H
#include <vector>

#include "BaseProblem.h"


class LeetCode1443MinimumTimeToCollectAllApplesInATree: BaseProblem {
    private:
    int minTime(int n, std::vector<std::vector<int>>& edges, std::vector<bool>& hasApple);
    public:
    void Run() override;
};



#endif //LEETCODE1443MINIMUMTIMETOCOLLECTALLAPPLESINATREE_H
