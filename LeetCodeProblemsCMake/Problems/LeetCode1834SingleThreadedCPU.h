//
// Created by saeed on 9/25/25.
//

#ifndef LEETCODEPROBLEMSCMAKE_LEETCODE1834SINGLETHREADEDCPU_H
#define LEETCODEPROBLEMSCMAKE_LEETCODE1834SINGLETHREADEDCPU_H
#include <vector>

#include "BaseProblem.h"


class LeetCode1834SingleThreadedCPU: BaseProblem {
private:
    std::vector<int> getOrder(std::vector<std::vector<int>>& tasks);
    public:
    void Run() override;
};


#endif //LEETCODEPROBLEMSCMAKE_LEETCODE1834SINGLETHREADEDCPU_H