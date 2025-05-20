//
// Created by saeed on 5/20/25.
//

#ifndef LEETCODE3355ZEROARRAYTRANSFORMATIONI_H
#define LEETCODE3355ZEROARRAYTRANSFORMATIONI_H
#include <vector>

#include "BaseProblem.h"


class LeetCode3355ZeroArrayTransformationI: BaseProblem {
private:
    bool isZeroArray(std::vector<int>& nums, std::vector<std::vector<int>>& queries);
    public:
    void Run() override;
};



#endif //LEETCODE3355ZEROARRAYTRANSFORMATIONI_H
