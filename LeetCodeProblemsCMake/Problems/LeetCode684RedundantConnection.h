//
// Created by saeed on 1/28/25.
//

#ifndef LEETCODE684REDUNDANTCONNECTION_H
#define LEETCODE684REDUNDANTCONNECTION_H
#include <vector>

#include "BaseProblem.h"


class LeetCode684RedundantConnection: BaseProblem {
    std::vector<int> findRedundantConnection(std::vector<std::vector<int>>& edges);
    public:
    void Run() override;
};



#endif //LEETCODE684REDUNDANTCONNECTION_H
