//
// Created by saeed on 2/7/25.
//

#ifndef LEETCODE241DIFFERENTWAYSTOADDPARENTHESES_H
#define LEETCODE241DIFFERENTWAYSTOADDPARENTHESES_H
#include <string>
#include <vector>

#include "BaseProblem.h"


class LeetCode241DifferentWaysToAddParentheses: BaseProblem {
    std::vector<int> diffWaysToCompute(std::string expression);
    public:
    void Run() override;
};



#endif //LEETCODE241DIFFERENTWAYSTOADDPARENTHESES_H
