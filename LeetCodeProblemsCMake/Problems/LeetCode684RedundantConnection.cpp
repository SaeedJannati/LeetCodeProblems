//
// Created by saeed on 1/28/25.
//

#include "LeetCode684RedundantConnection.h"

#include <numeric>

#include "../Auxilary/Auxilaries.h"
#pragma region  Union find
int mFind(std::vector<int> &parents, int vert) {
    if (parents[vert] != vert) {
        parents[vert] = mFind(parents, parents[vert]);
    }
    return parents[vert];
}

bool Union(std::vector<int> &parents, std::vector<int> &ranks, int vert1, int vert2) {
    int root1 = mFind(parents, vert1);
    int root2 = mFind(parents, vert2);
    if (root1 == root2)
        return false;
    if (ranks[root1] < ranks[root2]) {
        parents[root1] = root2;
        ranks[root2] += ranks[root1];;
    } else {
        parents[root2] = root1;
        ranks[root1] += ranks[root2];;
    }
    return true;
}

std::vector<int> LeetCode684RedundantConnection::findRedundantConnection(std::vector<std::vector<int> > &edges) {
    int length = static_cast<int>(edges.size());
    std::vector<int> parents(length + 1);
    std::iota(parents.begin(), parents.end(), 0);
    std::vector<int> ranks(length + 1, 1);
    for (auto &edge: edges) {
        if (!Union(parents, ranks, edge[0], edge[1]))
            return edge;
    }
    return edges.back();
}
#pragma endregion
#pragma region Dfs
// bool Dfs(std::unordered_map<int, std::pmr::unordered_set<int> > &adjPlus, std::vector<int> &path,
//          std::vector<bool> &visited, int parent, int node, int &cycleHead) {
//     if (visited[node]) {
//         cycleHead = node;
//         path.push_back(node);
//         return true;
//     }
//     visited[node] = true;
//     if (!adjPlus.contains(node))
//         return false;
//     for (auto vert: adjPlus[node]) {
//         if (vert == parent)
//             continue;
//         if (Dfs(adjPlus, path, visited, node, vert, cycleHead)) {
//             path.push_back(node);
//             return true;
//         }
//     }
//     return false;
// }
//
// std::vector<int> LeetCode684RedundantConnection::findRedundantConnection(std::vector<std::vector<int> > &edges) {
//     std::unordered_map<int, std::pmr::unordered_set<int> > adjPlus{};
//     for (auto edge: edges) {
//         if (!adjPlus.contains(edge[0])) {
//             adjPlus[edge[0]] = {};
//         }
//         adjPlus[edge[0]].insert(edge[1]);
//         if (!adjPlus.contains(edge[1])) {
//             adjPlus[edge[1]] = {};
//         }
//         adjPlus[edge[1]].insert(edge[0]);
//     }
//     std::vector<int> path{};
//     path.reserve(edges.size());
//     std::vector<bool> visited(edges.size() + 1, false);
//     int cycleHead = 0;
//     Dfs(adjPlus, path, visited, 0, 1, cycleHead);
//     std::unordered_set<int> cycleNodes{};
//     cycleNodes.reserve(path.size());
//     for (auto node: path) {
//         if (cycleNodes.contains(node))
//             break;
//         cycleNodes.insert(node);
//     }
//     for (int i = edges.size() - 1; i >= 0; i--) {
//         if (!cycleNodes.contains(edges[i][0]))
//             continue;
//         if (!cycleNodes.contains(edges[i][1]))
//             continue;
//         return edges[i];
//     }
//     return {};
// }
#pragma endregion
void LeetCode684RedundantConnection::Run() {
    std::vector<std::vector<int> > edges =
        // {{4, 5}, {1, 2}, {2, 4}, {3, 4}, {2, 3}};
    // {{1, 2}, {2, 3}, {1, 5}, {3, 4}, {1, 4}};
    {{1,2},{1,3},{2,3}};
    //     {
    //     {2, 7}, {7, 8}, {3, 6}, {2, 5}, {6, 8}, {4, 8}, {2, 8}, {1, 8}, {7, 10}, {3, 9}
    // };
    Auxilaries::PrintVector(findRedundantConnection(edges));
}
