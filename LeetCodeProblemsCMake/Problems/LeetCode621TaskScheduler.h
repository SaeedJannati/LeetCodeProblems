//
// Created by saeed on 10/8/25.
//

#ifndef LEETCODEPROBLEMSCMAKE_LEETCODE621TASKSCHEDULER_H
#define LEETCODEPROBLEMSCMAKE_LEETCODE621TASKSCHEDULER_H
#include <vector>

#include "BaseProblem.h"


class LeetCode621TaskScheduler: BaseProblem {
private:
    int leastInterval(std::vector<char>& tasks, int n);
public:
    void Run() override;
};


#endif //LEETCODEPROBLEMSCMAKE_LEETCODE621TASKSCHEDULER_H