//
// Created by saeed on 1/18/25.
//

#ifndef LEETCODE743NETWORKDELAYTIME_H
#define LEETCODE743NETWORKDELAYTIME_H
#include <vector>

#include "BaseProblem.h"


class LeetCode743NetworkDelayTime: BaseProblem {
    private:
    int networkDelayTime(std::vector<std::vector<int>>& times, int n, int k);
    public:
    void Run() override;
};



#endif //LEETCODE743NETWORKDELAYTIME_H
