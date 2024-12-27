#pragma once
#include <map>
#include <stack>
#include <vector>

#include "BaseProblem.h"

class GeeksForGeeksShortestPathInDirectedAcyclicGraph : BaseProblem
{
public:
    std::vector<int> shortestPath(int V, int E, std::vector<std::vector<int>>& edges);
    void Run() override;
    void TopologicalSort
    (std::map<int, std::map<int, int>>& adjPlus, std::vector<bool>& visited, std::stack<int>& topoStack, int vertex);
};
