//
// Created by saeed on 3/14/25.
//

#ifndef LEETCODE2226MAXIMUMCANDIESALLOCATEDTOKCHILDREN_H
#define LEETCODE2226MAXIMUMCANDIESALLOCATEDTOKCHILDREN_H
#include <vector>

#include "BaseProblem.h"


class LeetCode2226MaximumCandiesAllocatedToKChildren: BaseProblem {
private:
    int maximumCandies(std::vector<int>& candies, long long k);
    public:
    void Run() override;
};



#endif //LEETCODE2226MAXIMUMCANDIESALLOCATEDTOKCHILDREN_H
