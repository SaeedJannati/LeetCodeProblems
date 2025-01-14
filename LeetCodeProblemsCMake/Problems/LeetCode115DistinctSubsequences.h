//
// Created by saeed on 1/14/25.
//

#ifndef LEETCODE115DISTINCTSUBSEQUENCES_H
#define LEETCODE115DISTINCTSUBSEQUENCES_H
#include <string>

#include "BaseProblem.h"


class LeetCode115DistinctSubsequences: BaseProblem {
    private:
    int numDistinct(std::string s, std::string t);
    public:
    void Run() override;
};



#endif //LEETCODE115DISTINCTSUBSEQUENCES_H
