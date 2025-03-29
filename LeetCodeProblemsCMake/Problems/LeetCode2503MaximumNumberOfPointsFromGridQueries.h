//
// Created by saeed on 3/29/25.
//

#ifndef LEETCODE2503MAXIMUMNUMBEROFPOINTSFROMGRIDQUERIES_H
#define LEETCODE2503MAXIMUMNUMBEROFPOINTSFROMGRIDQUERIES_H
#include <vector>

#include "BaseProblem.h"


class LeetCode2503MaximumNumberOfPointsFromGridQueries: BaseProblem {
    private:
    static std::vector<int> maxPoints(std::vector<std::vector<int>>& grid, std::vector<int>& queries);
    public:
    void Run() override;
};



#endif //LEETCODE2503MAXIMUMNUMBEROFPOINTSFROMGRIDQUERIES_H
