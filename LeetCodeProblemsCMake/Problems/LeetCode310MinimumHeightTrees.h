//
// Created by saeed on 1/9/25.
//

#ifndef LEETCODE310MINIMUMHEIGHTTREES_H
#define LEETCODE310MINIMUMHEIGHTTREES_H
#include <iosfwd>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "BaseProblem.h"


class LeetCode310MinimumHeightTrees : BaseProblem{
private:
    std::vector<int> findMinHeightTrees(int n, std::vector<std::vector<int>>& edges);
public:
    void Run() override;

};



#endif //LEETCODE310MINIMUMHEIGHTTREES_H
