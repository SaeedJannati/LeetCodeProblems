//
// Created by saeed on 5/29/25.
//

#ifndef LEETCODE3373MAXIMIZETHENUMBEROFTARGETNODESAFTERCONNECTINGTREESII_H
#define LEETCODE3373MAXIMIZETHENUMBEROFTARGETNODESAFTERCONNECTINGTREESII_H
#include <vector>

#include "BaseProblem.h"


class LeetCode3373MaximizeTheNumberOfTargetNodesAfterConnectingTreesII: BaseProblem {
    private:
    std::vector<int> maxTargetNodes(std::vector<std::vector<int>>& edges1, std::vector<std::vector<int>>& edges2);
    public:
    void Run() override;
};



#endif //LEETCODE3373MAXIMIZETHENUMBEROFTARGETNODESAFTERCONNECTINGTREESII_H
