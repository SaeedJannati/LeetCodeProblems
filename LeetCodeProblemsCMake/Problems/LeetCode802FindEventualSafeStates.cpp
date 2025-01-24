//
// Created by saeed on 1/24/25.
//

#include "LeetCode802FindEventualSafeStates.h"

#include "../Auxilary/Auxilaries.h"

bool LeetCode802FindEventualSafeStates::Dfs( std::vector<std::vector<int> > &graph,std::vector<int> &visited,int i) {
    if (visited[i]==1)
        return  false;
    if (visited[i]==2)
        return true;
    visited[i] = 1;
    if (graph[i].empty()) {
        visited[i] = 2;
        return true;
    }
    for(auto num:graph[i]) {
        if (!Dfs(graph, visited, num)) {
            visited[num] = 1;
            return false;
        }
    }
    visited[i] = 2;
    return true;
}

std::vector<int> LeetCode802FindEventualSafeStates::eventualSafeNodes(std::vector<std::vector<int> > &graph) {
    int length = static_cast<int>(graph.size());
    std::vector<int> result{};
    result.reserve(length);
    std::vector<int> visited(length,0);
    for (int i = 0; i < length; i++) {
        if (!Dfs(graph, visited, i))
            continue;
        result.push_back(i);
    }
    return result;
}

void LeetCode802FindEventualSafeStates::Run() {
    std::vector<std::vector<int> > graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    auto result = eventualSafeNodes(graph);
    Auxilaries::PrintVector(result);
}
