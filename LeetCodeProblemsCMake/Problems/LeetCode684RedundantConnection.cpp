//
// Created by saeed on 1/28/25.
//

#include "LeetCode684RedundantConnection.h"

#include <unordered_map>
#include <unordered_set>

#include "../Auxilary/Auxilaries.h"

bool Dfs(std::unordered_map<int, std::pmr::unordered_set<int> > &adjPlus, std::vector<int> &path,
         std::vector<bool> &visited, int parent, int node, int &cycleHead) {
    if (visited[node]) {
        cycleHead = node;
        path.push_back(node);
        return true;
    }
    visited[node] = true;
    if (!adjPlus.contains(node))
        return false;
    for (auto vert: adjPlus[node]) {
        if (vert == parent)
            continue;
        if (Dfs(adjPlus, path, visited, node, vert, cycleHead)) {
            path.push_back(node);
            return true;
        }
    }
    return false;
}

std::vector<int> LeetCode684RedundantConnection::findRedundantConnection(std::vector<std::vector<int> > &edges) {
    std::unordered_map<int, std::pmr::unordered_set<int> > adjPlus{};
    for (auto edge: edges) {
        if (!adjPlus.contains(edge[0])) {
            adjPlus[edge[0]] = {};
        }
        adjPlus[edge[0]].insert(edge[1]);
        if (!adjPlus.contains(edge[1])) {
            adjPlus[edge[1]] = {};
        }
        adjPlus[edge[1]].insert(edge[0]);
    }
    std::vector<int> path{};
    path.reserve(edges.size());
    std::vector<bool> visited(edges.size() + 1, false);
    int cycleHead = 0;
    Dfs(adjPlus, path, visited, 0, 1, cycleHead);
    std::unordered_set<int> cycleNodes{};
    cycleNodes.reserve(path.size());
    for (auto node: path) {
        if (cycleNodes.contains(node))
            break;
        cycleNodes.insert(node);
    }
    for (int i = edges.size() - 1; i >= 0; i--) {
        if (!cycleNodes.contains(edges[i][0]))
            continue;
        if (!cycleNodes.contains(edges[i][1]))
            continue;
        return edges[i];
    }
    return {};
}

void LeetCode684RedundantConnection::Run() {
    std::vector<std::vector<int> > edges = {
        {2, 7}, {7, 8}, {3, 6}, {2, 5}, {6, 8}, {4, 8}, {2, 8}, {1, 8}, {7, 10}, {3, 9}
    };
    Auxilaries::PrintVector(findRedundantConnection(edges));
}
