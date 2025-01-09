//
// Created by saeed on 1/9/25.
//

#include "LeetCode1443MinimumTimeToCollectAllApplesInATree.h"

#include <iostream>
#include <unordered_map>
#include <unordered_set>

bool FillHasAppleBelow(std::unordered_map<int, std::unordered_set<int> > &adjPlus,std::vector<bool>& visited, std::vector<bool> &hasApple,
                       std::vector<bool> &hasAppleBelow, int parent, int node) {
    if (visited[node])
        return hasApple[node];
    visited[node] = true;
    bool hasBelow = hasApple[node];
    for (const auto &child: adjPlus[node]) {
        hasBelow |= FillHasAppleBelow(adjPlus, visited,hasApple, hasAppleBelow, node, child);
    }
    if (hasBelow)
        hasAppleBelow[parent] = true;
    return hasBelow;
}
void CollectApplesBelow(std::unordered_map<int, std::unordered_set<int> > &adjPlus,std::vector<bool>& visited, std::vector<bool> &hasApple,
                       std::vector<bool> &hasAppleBelow, int node,int& elapsedTime) {
    if (visited[node])
        return;
    visited[node] = true;
    if (!hasAppleBelow[node]) {
        if (hasApple[node]) {
            elapsedTime+=2;
        }
        return;
    }
    elapsedTime+=2;
    for (const auto &child: adjPlus[node]) {
        CollectApplesBelow(adjPlus,visited, hasApple, hasAppleBelow, child, elapsedTime);
    }
}
int LeetCode1443MinimumTimeToCollectAllApplesInATree::minTime(int n, std::vector<std::vector<int> > &edges,
                                                              std::vector<bool> &hasApple) {
    std::unordered_map<int, std::unordered_set<int> > adjPlus;
    for (const auto &edge: edges) {
        adjPlus[edge[0]].insert(edge[1]);
        adjPlus[edge[1]].insert(edge[0]);
    }
    std::vector<bool> hasAppleBelow(n, false);
    std::vector<bool> visited(n, false);
    visited[0] = true;
    for (const auto &node: adjPlus[0]) {
        FillHasAppleBelow(adjPlus, visited,hasApple, hasAppleBelow, 0, node);
    }
   for (int i=0;i<n;i++) {
       visited[i] = false;
   }
    int elapsedTime=0;
    CollectApplesBelow(adjPlus, visited,hasApple, hasAppleBelow, 0, elapsedTime);
    return std::max(elapsedTime-2,0);
}

void LeetCode1443MinimumTimeToCollectAllApplesInATree::Run() {
    std::vector<std::vector<int> > edges={{0, 2}, {0, 3}, {1, 2}};
    std::vector<bool> hasApple={false,true,false,false};
    int n=4;
    std::cout<<minTime(n, edges, hasApple)<<std::endl;
}
