//
// Created by saeed on 3/13/25.
//

#ifndef LEETCODE3356ZEROARRAYTRANSFORMATIONII_H
#define LEETCODE3356ZEROARRAYTRANSFORMATIONII_H
#include <vector>

#include "BaseProblem.h"


class LeetCode3356ZeroArrayTransformationII: BaseProblem {
private:
    int minZeroArray(std::vector<int>& nums, std::vector<std::vector<int>>& queries) ;
    public:
    void Run() override;
};



#endif //LEETCODE3356ZEROARRAYTRANSFORMATIONII_H
