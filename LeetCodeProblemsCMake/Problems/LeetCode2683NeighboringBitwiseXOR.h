//
// Created by saeed on 1/17/25.
//

#ifndef LEETCODE2683NEIGHBORINGBITWISEXOR_H
#define LEETCODE2683NEIGHBORINGBITWISEXOR_H
#include <vector>

#include "BaseProblem.h"


class LeetCode2683NeighboringBitwiseXOR: BaseProblem {
    private:
    bool doesValidArrayExist(std::vector<int>& derived);
    public:
    void Run() override;
};



#endif //LEETCODE2683NEIGHBORINGBITWISEXOR_H
