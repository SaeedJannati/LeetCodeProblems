//
// Created by saeed on 12/1/25.
//

#ifndef LEETCODEPROBLEMSCMAKE_LEETCODE2141MAXIMUMRUNNINGTIMEOFNCOMPUTERS_H
#define LEETCODEPROBLEMSCMAKE_LEETCODE2141MAXIMUMRUNNINGTIMEOFNCOMPUTERS_H
#include <vector>

#include "BaseProblem.h"


class LeetCode2141MaximumRunningTimeOfNComputers: BaseProblem {
    long long maxRunTime(int n, std::vector<int>& batteries);
public:
    void Run() override;
};
#endif //LEETCODEPROBLEMSCMAKE_LEETCODE2141MAXIMUMRUNNINGTIMEOFNCOMPUTERS_H
