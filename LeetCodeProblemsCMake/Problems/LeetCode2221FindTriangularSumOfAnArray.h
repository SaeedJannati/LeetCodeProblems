//
// Created by saeed on 9/30/25.
//

#ifndef LEETCODEPROBLEMSCMAKE_LEETCODE2221FINDTRIANGULARSUMOFANARRAY_H
#define LEETCODEPROBLEMSCMAKE_LEETCODE2221FINDTRIANGULARSUMOFANARRAY_H
#include <vector>

#include "BaseProblem.h"


class LeetCode2221FindTriangularSumOfAnArray: BaseProblem {
private:
    int triangularSum(std::vector<int>& nums);
public:
    void Run() override;
};


#endif //LEETCODEPROBLEMSCMAKE_LEETCODE2221FINDTRIANGULARSUMOFANARRAY_H