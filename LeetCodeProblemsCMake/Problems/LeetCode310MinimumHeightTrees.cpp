//
// Created by saeed on 1/9/25.
//

#include "LeetCode310MinimumHeightTrees.h"

#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <ostream>
#include <unordered_map>
#include <unordered_set>

#include "../Auxilary/Auxilaries.h"

std::vector<int> LeetCode310MinimumHeightTrees::findMinHeightTrees(int n, std::vector<std::vector<int> > &edges) {
    if (n == 1)
        return {0};
    if (n == 2)
        return {0, 1};
    std::unordered_map<int, std::unordered_set<int> > adjPlus;
    std::unordered_set<int> nodesWithOnePlusEdge;
    nodesWithOnePlusEdge.reserve(n);
    for (int i = 0; i < n; ++i) {
        nodesWithOnePlusEdge.insert(i);
    }
    for (auto edge: edges) {
        if (!adjPlus.contains(edge[0])) {
            std::unordered_set<int> neighbours;
            adjPlus[edge[0]] = neighbours;
        } else {
            if (nodesWithOnePlusEdge.contains(edge[0]))
                nodesWithOnePlusEdge.erase(edge[0]);
        }
        adjPlus[edge[0]].insert(edge[1]);
        if (!adjPlus.contains(edge[1])) {
            std::unordered_set<int> neighbours;
            adjPlus[edge[1]] = neighbours;
        } else {
            if (nodesWithOnePlusEdge.contains(edge[1]))
                nodesWithOnePlusEdge.erase(edge[1]);
        }
        adjPlus[edge[1]].insert(edge[0]);
    }
    while (adjPlus.size()!=0&&nodesWithOnePlusEdge.size() != adjPlus.size()) {
        std::unordered_set<int> nextLayer;
        for (const auto node: nodesWithOnePlusEdge) {
            for (const auto edge: adjPlus[node]) {
                adjPlus[edge].erase(node);
                if (adjPlus[edge].size() == 0) {
                    adjPlus.erase(edge);
                    continue;
                }
                if (adjPlus[edge].size() == 1) {
                    nextLayer.insert(edge);
                }
            }
            adjPlus.erase(node);
        }
        nodesWithOnePlusEdge = nextLayer;
    }
    std::vector<int> result(nodesWithOnePlusEdge.begin(), nodesWithOnePlusEdge.end());
    return result;
}

void LeetCode310MinimumHeightTrees::Run() {
    std::vector<std::vector<int> > edges = {
        {0, 1}, {0, 2}, {0, 3}, {2, 4}, {0, 5}, {5, 6}, {6, 7}, {2, 8}, {7, 9}
    };
    // {
    //     {1, 0}, {1, 2}, {1, 3}
    // };
    int n = 10;
    auto result = findMinHeightTrees(n, edges);
    Auxilaries::PrintVector(result);
}
