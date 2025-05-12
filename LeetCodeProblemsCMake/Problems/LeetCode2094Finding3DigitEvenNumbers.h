//
// Created by saeed on 5/12/25.
//

#ifndef LEETCODE2094FINDING3DIGITEVENNUMBERS_H
#define LEETCODE2094FINDING3DIGITEVENNUMBERS_H
#include <vector>

#include "BaseProblem.h"


class LeetCode2094Finding3DigitEvenNumbers : BaseProblem{
    private:
    std::vector<int> findEvenNumbers(std::vector<int>& digits);
    public:
    void Run() override;
};



#endif //LEETCODE2094FINDING3DIGITEVENNUMBERS_H
