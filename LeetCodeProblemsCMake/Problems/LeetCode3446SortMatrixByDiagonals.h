//
// Created by saeed on 8/28/25.
//

#ifndef LEETCODE3446SORTMATRIXBYDIAGONALS_H
#define LEETCODE3446SORTMATRIXBYDIAGONALS_H
#include <vector>

#include "BaseProblem.h"


class LeetCode3446SortMatrixByDiagonals: BaseProblem {
    private:
    std::vector<std::vector<int>> sortMatrix(std::vector<std::vector<int>>& grid);
    public:
    void Run() override;
};



#endif //LEETCODE3446SORTMATRIXBYDIAGONALS_H
