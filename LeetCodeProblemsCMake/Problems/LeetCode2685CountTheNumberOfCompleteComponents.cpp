//
// Created by saeed on 3/22/25.
//

#include "LeetCode2685CountTheNumberOfCompleteComponents.h"

#include <iostream>
#include <numeric>
#include <ostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#pragma region Union find
int LeetCode2685CountTheNumberOfCompleteComponents::Find(vector<int> &parents, int node) {
    if (parents[node] != node) {
        parents[node] = Find(parents, parents[node]);
    }
    return parents[node];
}

bool LeetCode2685CountTheNumberOfCompleteComponents::Union(vector<int> &parents, vector<int> &ranks, int first,
                                                           int second) {
    int firstParent = Find(parents, first);
    int secondParent = Find(parents, second);
    if (firstParent == secondParent) {
        return false;
    }
    if (ranks[firstParent] > ranks[secondParent]) {
        parents[secondParent] = firstParent;
    } else if (ranks[firstParent] < ranks[secondParent]) {
        parents[firstParent] = secondParent;
    } else {
        parents[secondParent] = firstParent;
        ranks[firstParent]++;
    }
    return true;
}

int LeetCode2685CountTheNumberOfCompleteComponents::
countCompleteComponents(int n, std::vector<std::vector<int> > &edges) {
    vector<int> ranks(n, 0);
    vector<int> parents(n, 0);
    iota(parents.begin(), parents.end(), 0);
    for (auto &edge: edges) {
        Union(parents, ranks, edge[0], edge[1]);
    }
    for (int i = 0; i < n; i++) {
        Find(parents, i);
    }
    int result{};
    unordered_map<int, unordered_set<int> > segments{};
    unordered_map<int, int> segmentEdgeCount{};
    for (int i = 0; i < n; i++) {
        if (!segments.contains(parents[i])) {
            segments[parents[i]] = {};
            segmentEdgeCount[parents[i]] = 0;
        }
        segments[parents[i]].insert(i);
    }
    int edgePerent{};
    for (auto &edge: edges) {
        edgePerent = Find(parents, edge[0]);
        segmentEdgeCount[edgePerent]++;
    }
    int edgeCount{};
    int vertCount{};
    for (auto &segment: segments) {
        edgeCount = segmentEdgeCount[segment.first];
        vertCount = segment.second.size();
        if (edgeCount == vertCount * (vertCount - 1) / 2)
            result++;
    }
    return result;
}
#pragma endregion
#pragma region Dfs
// void Dfs(unordered_map<int,unordered_set<int>> &adjPlus,vector<bool>& visited,int node,int & segmentVertCount,int & segmentEdgeCount) {
//     if (!adjPlus.contains(node))
//         return;
//     for (auto vert:adjPlus[node]) {
//         segmentEdgeCount++;
//         if (visited[vert])
//             continue;
//         visited[vert] = true;
//         segmentVertCount++;
//         Dfs(adjPlus,visited,vert,segmentVertCount,segmentEdgeCount);
//     }
// }
// int LeetCode2685CountTheNumberOfCompleteComponents::
// countCompleteComponents(int n, std::vector<std::vector<int>> &edges) {
//     vector<bool> visited(n, false);
//     unordered_map<int,unordered_set<int>> adjPlus{};
//     for (auto &edge : edges) {
//         if (!adjPlus.contains(edge[0]))
//             adjPlus[edge[0]]={};
//         adjPlus[edge[0]].insert(edge[1]);
//         if (!adjPlus.contains(edge[1]))
//             adjPlus[edge[1]]={};
//         adjPlus[edge[1]].insert(edge[0]);
//     }
//     int result{};
//     int segmentVertCount{};
//     int segmentEdgeCount{};
//     for (int i=0;i<n;i++) {
//         segmentVertCount=1;
//         segmentEdgeCount=0;
//         if (visited[i])
//             continue;
//         visited[i]=true;
//         Dfs(adjPlus,visited,i,segmentVertCount,segmentEdgeCount);
//         if (segmentEdgeCount== segmentVertCount*(segmentVertCount-1)) {
//             result++;
//         }
//     }
//     return result;
// }
#pragma endregion Dfs
void LeetCode2685CountTheNumberOfCompleteComponents::Run() {
    int n = 4;
    vector<vector<int> > edges{{2,1},{3,0},{3,1}};
    cout << countCompleteComponents(n, edges) << endl;
}
