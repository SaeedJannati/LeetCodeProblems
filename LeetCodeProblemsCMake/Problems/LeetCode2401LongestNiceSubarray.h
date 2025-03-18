//
// Created by saeed on 3/18/25.
//

#ifndef LEETCODE2401LONGESTNICESUBARRAY_H
#define LEETCODE2401LONGESTNICESUBARRAY_H
#include <vector>

#include "BaseProblem.h"


class LeetCode2401LongestNiceSubarray : BaseProblem{
    private:
    int longestNiceSubarray(std::vector<int>& nums);
public:
    void Run() override;
};



#endif //LEETCODE2401LONGESTNICESUBARRAY_H
