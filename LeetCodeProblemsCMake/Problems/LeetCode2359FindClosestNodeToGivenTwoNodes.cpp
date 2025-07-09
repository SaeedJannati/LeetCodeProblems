//
// Created by saeed on 5/30/25.
//

#include "LeetCode2359FindClosestNodeToGivenTwoNodes.h"

#include <iostream>
#include <limits>
#include <unordered_map>
using namespace std;

void Dfs(vector<int> &edges, vector<bool> &visited, vector<int> &distances, int node, int distance) {
    auto next = edges[node];
    if (next == -1||visited[next] )
        return;
    visited[next] = true;
    distances[next] = distance;
    Dfs(edges, visited, distances, next, distance + 1);
}

int LeetCode2359FindClosestNodeToGivenTwoNodes::closestMeetingNode(vector<int> &edges, int node1, int node2) {
    int length = static_cast<int>(edges.size());
    vector<bool> visited(length, false);
    vector<int> distanceToFirstNode(length, -1);
    vector<int> distanceToSecondNode(length, -1);
    visited[node1] = true;
    distanceToFirstNode[node1] = 0;
    Dfs(edges, visited, distanceToFirstNode, node1, 1);
    visited = vector<bool>(length, false);
    visited[node2] = true;
    distanceToSecondNode[node2] = 0;
    Dfs(edges, visited, distanceToSecondNode, node2, 1);
    int maxInt = numeric_limits<int>::max();
    int minMaxDistance = maxInt;
    int destNode{};
    for (int i = 0; i < length; i++) {
        if (distanceToFirstNode[i] < 0)
            continue;
        if (distanceToSecondNode[i] < 0)
            continue;
        auto maxDistance = std::max(distanceToFirstNode[i], distanceToSecondNode[i]);
        if (maxDistance < minMaxDistance) {
            minMaxDistance = maxDistance;
            destNode = i;
        }
    }
    if (minMaxDistance == maxInt)
        return -1;
    return destNode;
}

void LeetCode2359FindClosestNodeToGivenTwoNodes::Run() {
    vector<int>edges{4,4,4,5,1,2,2};
    int node1=1;
    int node2=1;
    std::cout<<closestMeetingNode(edges, node1, node2);
}
