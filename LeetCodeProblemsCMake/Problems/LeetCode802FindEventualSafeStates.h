//
// Created by saeed on 1/24/25.
//

#ifndef LEETCODE802FINDEVENTUALSAFESTATES_H
#define LEETCODE802FINDEVENTUALSAFESTATES_H
#include <iosfwd>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "BaseProblem.h"


class LeetCode802FindEventualSafeStates: BaseProblem {
private:
   bool Dfs( std::vector<std::vector<int> > &graph,std::vector<int> &visited,int i) ;

    std::vector<int> eventualSafeNodes(std::vector<std::vector<int>>& graph);
public:
    void Run() override;
};



#endif //LEETCODE802FINDEVENTUALSAFESTATES_H
