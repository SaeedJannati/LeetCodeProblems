//
// Created by saeed on 2/27/25.
//

#ifndef LEETCODE873LENGTHOFLONGESTFIBONACCISUBSEQUENCE_H
#define LEETCODE873LENGTHOFLONGESTFIBONACCISUBSEQUENCE_H
#include <vector>

#include "BaseProblem.h"


class LeetCode873LengthOfLongestFibonacciSubsequence: BaseProblem {
private:
    int lenLongestFibSubseq(std::vector<int>& arr);
    public:
    void Run() override;
};



#endif //LEETCODE873LENGTHOFLONGESTFIBONACCISUBSEQUENCE_H
