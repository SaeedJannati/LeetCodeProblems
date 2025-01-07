//
// Created by saeed on 1/7/25.
//

#ifndef LEETCODE85MAXIMALRECTANGLE_H
#define LEETCODE85MAXIMALRECTANGLE_H
#include <vector>

#include "BaseProblem.h"


class LeetCode85MaximalRectangle: BaseProblem {
private:
    int maximalRectangle(std::vector<std::vector<char>>& matrix);
public:
    void Run() override;
};



#endif //LEETCODE85MAXIMALRECTANGLE_H
