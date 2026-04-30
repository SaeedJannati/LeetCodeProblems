//
// Created by Saeed Jannati on 4/30/2026 A.
//

#ifndef LEETCODEPROBLEMSCMAKE_LEETCODE3742MAXIMUMPATHSCOREINAGRID_H
#define LEETCODEPROBLEMSCMAKE_LEETCODE3742MAXIMUMPATHSCOREINAGRID_H
#include <vector>

#include "BaseProblem.h"


class LeetCode3742MaximumPathScoreInAGrid: BaseProblem {
private:
    int maxPathScore(std::vector<std::vector<int>>& grid, int k);
    public:
    void Run() override;
};




#endif //LEETCODEPROBLEMSCMAKE_LEETCODE3742MAXIMUMPATHSCOREINAGRID_H
