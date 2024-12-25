#pragma once
#include <vector>

#include "BaseProblem.h"

class GeeksForGeeksShortestPathInDirectedAcyclicGraph: BaseProblem
{
public:
    std::vector<int> shortestPath(int V, int E, std::vector<std::vector<int>>& edges);
    void Run() override;;
};
