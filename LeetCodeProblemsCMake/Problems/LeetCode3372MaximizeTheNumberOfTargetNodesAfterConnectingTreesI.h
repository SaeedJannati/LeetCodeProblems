//
// Created by saeed on 5/28/25.
//

#ifndef LEETCODE3372MAXIMIZETHENUMBEROFTARGETNODESAFTERCONNECTINGTREESI_H
#define LEETCODE3372MAXIMIZETHENUMBEROFTARGETNODESAFTERCONNECTINGTREESI_H
#include <vector>

#include "BaseProblem.h"


class LeetCode3372MaximizeTheNumberOfTargetNodesAfterConnectingTreesI: BaseProblem {
private:
    std::vector<int> maxTargetNodes(std::vector<std::vector<int>>& edges1, std::vector<std::vector<int>>& edges2, int k);
    public:
    void Run() override;
};



#endif //LEETCODE3372MAXIMIZETHENUMBEROFTARGETNODESAFTERCONNECTINGTREESI_H
