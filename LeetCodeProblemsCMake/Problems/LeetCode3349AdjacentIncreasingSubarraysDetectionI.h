//
// Created by saeed on 10/14/25.
//

#ifndef LEETCODEPROBLEMSCMAKE_LEETCODE3349ADJACENTINCREASINGSUBARRAYSDETECTIONI_H
#define LEETCODEPROBLEMSCMAKE_LEETCODE3349ADJACENTINCREASINGSUBARRAYSDETECTIONI_H
#include <vector>

#include "BaseProblem.h"


class LeetCode3349AdjacentIncreasingSubarraysDetectionI: BaseProblem {
private:
    bool hasIncreasingSubarrays(std::vector<int>& nums, int k) ;
public:
    void Run() override;
};


#endif //LEETCODEPROBLEMSCMAKE_LEETCODE3349ADJACENTINCREASINGSUBARRAYSDETECTIONI_H