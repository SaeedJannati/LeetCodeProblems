//
// Created by saeed on 3/24/25.
//

#ifndef LEETCODE3169COUNTDAYSWITHOUTMEETINGS_H
#define LEETCODE3169COUNTDAYSWITHOUTMEETINGS_H
#include <vector>

#include "BaseProblem.h"


class LeetCode3169CountDaysWithoutMeetings: BaseProblem {
    private:
    int countDays(int days, std::vector<std::vector<int>>& meetings);
    public:
    void Run() override;
};



#endif //LEETCODE3169COUNTDAYSWITHOUTMEETINGS_H
