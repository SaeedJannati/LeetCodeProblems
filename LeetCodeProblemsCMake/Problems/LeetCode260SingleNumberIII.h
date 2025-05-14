//
// Created by saeed on 5/14/25.
//

#ifndef LEETCODE260SINGLENUMBERIII_H
#define LEETCODE260SINGLENUMBERIII_H
#include <vector>

#include "BaseProblem.h"


class LeetCode260SingleNumberIII: BaseProblem {
    private:
    std::vector<int> singleNumber(std::vector<int>& nums);
    public:
    void Run() override;
};



#endif //LEETCODE260SINGLENUMBERIII_H
