//
// Created by saeed on 1/6/25.
//

#ifndef LEETCODE881BOATSTOSAVEPEOPLE_H
#define LEETCODE881BOATSTOSAVEPEOPLE_H
#include <vector>

#include "BaseProblem.h"


class LeetCode881BoatsToSavePeople: BaseProblem {
    private:
    int numRescueBoats(std::vector<int>& people, int limit);
    public:
    void Run() override;
};



#endif //LEETCODE881BOATSTOSAVEPEOPLE_H
