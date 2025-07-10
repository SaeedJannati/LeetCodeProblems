//
// Created by saeed on 7/10/25.
//

#ifndef LEETCODE3440RESCHEDULEMEETINGSFORMAXIMUMFREETIMEII_H
#define LEETCODE3440RESCHEDULEMEETINGSFORMAXIMUMFREETIMEII_H
#include <vector>

#include "BaseProblem.h"


class LeetCode3440RescheduleMeetingsForMaximumFreeTimeII: BaseProblem {
    int maxFreeTime(int eventTime, std::vector<int>& startTime, std::vector<int>& endTime);
    public:
    void Run() override;
};



#endif //LEETCODE3440RESCHEDULEMEETINGSFORMAXIMUMFREETIMEII_H
