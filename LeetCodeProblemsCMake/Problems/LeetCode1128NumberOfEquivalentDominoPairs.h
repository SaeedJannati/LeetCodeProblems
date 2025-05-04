//
// Created by saeed on 5/4/25.
//

#ifndef LEETCODE1128NUMBEROFEQUIVALENTDOMINOPAIRS_H
#define LEETCODE1128NUMBEROFEQUIVALENTDOMINOPAIRS_H
#include <vector>

#include "BaseProblem.h"


class LeetCode1128NumberOfEquivalentDominoPairs: BaseProblem{
    private:
    int numEquivDominoPairs(std::vector<std::vector<int>>& dominoes);
    public:
    void Run() override;
};



#endif //LEETCODE1128NUMBEROFEQUIVALENTDOMINOPAIRS_H
