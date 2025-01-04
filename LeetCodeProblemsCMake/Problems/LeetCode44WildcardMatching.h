//
// Created by saeed on 1/4/25.
//

#ifndef LEETCODE44WILDCARDMATCHING_H
#define LEETCODE44WILDCARDMATCHING_H
#include <string>

#include "BaseProblem.h"


class LeetCode44WildcardMatching: BaseProblem {
private:
    bool isMatch(std::string s, std::string p);
    public:
    void Run() override;
};



#endif //LEETCODE44WILDCARDMATCHING_H
