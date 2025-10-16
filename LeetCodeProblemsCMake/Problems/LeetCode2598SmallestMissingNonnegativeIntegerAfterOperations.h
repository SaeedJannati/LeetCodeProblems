//
// Created by saeed on 10/16/25.
//

#ifndef LEETCODEPROBLEMSCMAKE_LEETCODE2598SMALLESTMISSINGNONNEGATIVEINTEGERAFTEROPERATIONS_H
#define LEETCODEPROBLEMSCMAKE_LEETCODE2598SMALLESTMISSINGNONNEGATIVEINTEGERAFTEROPERATIONS_H
#include <vector>

#include "BaseProblem.h"


class LeetCode2598SmallestMissingNonnegativeIntegerAfterOperations: BaseProblem {
    private:
    int findSmallestInteger(std::vector<int>& nums, int value);
    public:
    void Run() override;
};


#endif //LEETCODEPROBLEMSCMAKE_LEETCODE2598SMALLESTMISSINGNONNEGATIVEINTEGERAFTEROPERATIONS_H