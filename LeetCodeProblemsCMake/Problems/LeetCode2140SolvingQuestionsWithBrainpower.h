//
// Created by saeed on 4/1/25.
//

#ifndef LEETCODE2140SOLVINGQUESTIONSWITHBRAINPOWER_H
#define LEETCODE2140SOLVINGQUESTIONSWITHBRAINPOWER_H
#include <vector>

#include "BaseProblem.h"


class LeetCode2140SolvingQuestionsWithBrainpower: BaseProblem {
private:
    long long mostPoints(std::vector<std::vector<int>>& questions);
public:
    void Run() override;
};



#endif //LEETCODE2140SOLVINGQUESTIONSWITHBRAINPOWER_H
