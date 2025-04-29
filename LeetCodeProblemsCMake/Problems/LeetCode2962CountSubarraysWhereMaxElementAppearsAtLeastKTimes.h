//
// Created by saeed on 4/29/25.
//

#ifndef LEETCODE2962COUNTSUBARRAYSWHEREMAXELEMENTAPPEARSATLEASTKTIMES_H
#define LEETCODE2962COUNTSUBARRAYSWHEREMAXELEMENTAPPEARSATLEASTKTIMES_H
#include <vector>

#include "BaseProblem.h"


class LeetCode2962CountSubarraysWhereMaxElementAppearsAtLeastKTimes: BaseProblem {
private:
    long long countSubarrays(std::vector<int>& nums, int k);
public:
    void Run() override;
};



#endif //LEETCODE2962COUNTSUBARRAYSWHEREMAXELEMENTAPPEARSATLEASTKTIMES_H
