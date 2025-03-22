//
// Created by saeed on 3/22/25.
//

#ifndef LEETCODE2685COUNTTHENUMBEROFCOMPLETECOMPONENTS_H
#define LEETCODE2685COUNTTHENUMBEROFCOMPLETECOMPONENTS_H
#include <vector>

#include "BaseProblem.h"


class LeetCode2685CountTheNumberOfCompleteComponents: BaseProblem {
private:
    int Find(std::vector<int> &parents, int node);

    bool Union(std::vector<int> &parents, std::vector<int> &ranks, int first, int second);

    int countCompleteComponents(int n, std::vector<std::vector<int>>& edges);
public:
    void Run() override;
};



#endif //LEETCODE2685COUNTTHENUMBEROFCOMPLETECOMPONENTS_H
