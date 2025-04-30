//
// Created by saeed on 4/30/25.
//

#ifndef LEETCODE1295FINDNUMBERSWITHEVENNUMBEROFDIGITS_H
#define LEETCODE1295FINDNUMBERSWITHEVENNUMBEROFDIGITS_H
#include <vector>

#include "BaseProblem.h"


class LeetCode1295FindNumbersWithEvenNumberOfDigits: BaseProblem {
    private:
    int findNumbers(std::vector<int>& nums);
    public:
    void Run() override;
};



#endif //LEETCODE1295FINDNUMBERSWITHEVENNUMBEROFDIGITS_H
