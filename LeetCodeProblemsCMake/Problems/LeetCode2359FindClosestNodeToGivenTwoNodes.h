//
// Created by saeed on 5/30/25.
//

#ifndef LEETCODE2359FINDCLOSESTNODETOGIVENTWONODES_H
#define LEETCODE2359FINDCLOSESTNODETOGIVENTWONODES_H
#include <vector>

#include "BaseProblem.h"


class LeetCode2359FindClosestNodeToGivenTwoNodes: BaseProblem{
    int closestMeetingNode(std::vector<int>& edges, int node1, int node2);
    public:
    void Run() override;
};



#endif //LEETCODE2359FINDCLOSESTNODETOGIVENTWONODES_H
