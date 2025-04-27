//
// Created by saeed on 4/27/25.
//

#ifndef LEETCODE3392COUNTSUBARRAYSOFLENGTHTHREEWITHACONDITION_H
#define LEETCODE3392COUNTSUBARRAYSOFLENGTHTHREEWITHACONDITION_H
#include <vector>

#include "BaseProblem.h"


class LeetCode3392CountSubarraysOfLengthThreeWithACondition : BaseProblem{
private:
    int countSubarrays(std::vector<int>& nums);
    public:
    void Run() override;
};



#endif //LEETCODE3392COUNTSUBARRAYSOFLENGTHTHREEWITHACONDITION_H
