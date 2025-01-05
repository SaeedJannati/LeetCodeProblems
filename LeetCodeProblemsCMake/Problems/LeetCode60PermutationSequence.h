//
// Created by saeed on 1/5/25.
//

#ifndef LEETCODE60PERMUTATIONSEQUENCE_H
#define LEETCODE60PERMUTATIONSEQUENCE_H
#include <string>

#include "BaseProblem.h"


class LeetCode60PermutationSequence: BaseProblem {
    private:
    std::string getPermutation(int n, int k);

    int CalcFactorial(int n);
public:
void Run() override;
};



#endif //LEETCODE60PERMUTATIONSEQUENCE_H
