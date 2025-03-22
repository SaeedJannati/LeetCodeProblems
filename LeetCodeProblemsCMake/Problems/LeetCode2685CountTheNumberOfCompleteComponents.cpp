//
// Created by saeed on 3/22/25.
//

#include "LeetCode2685CountTheNumberOfCompleteComponents.h"

#include <iostream>
#include <ostream>
#include <unordered_map>
#include <unordered_set>
using  namespace std;
void Dfs(unordered_map<int,unordered_set<int>> &adjPlus,vector<bool>& visited,int node,int & segmentVertCount,int & segmentEdgeCount) {
    if (!adjPlus.contains(node))
        return;
    for (auto vert:adjPlus[node]) {
        segmentEdgeCount++;
        if (visited[vert])
            continue;
        visited[vert] = true;
        segmentVertCount++;
        Dfs(adjPlus,visited,vert,segmentVertCount,segmentEdgeCount);
    }
}
int LeetCode2685CountTheNumberOfCompleteComponents::
countCompleteComponents(int n, std::vector<std::vector<int>> &edges) {
    vector<bool> visited(n, false);
    unordered_map<int,unordered_set<int>> adjPlus{};
    for (auto &edge : edges) {
        if (!adjPlus.contains(edge[0]))
            adjPlus[edge[0]]={};
        adjPlus[edge[0]].insert(edge[1]);
        if (!adjPlus.contains(edge[1]))
            adjPlus[edge[1]]={};
        adjPlus[edge[1]].insert(edge[0]);
    }
    int result{};
    int segmentVertCount{};
    int segmentEdgeCount{};
    for (int i=0;i<n;i++) {
        segmentVertCount=1;
        segmentEdgeCount=0;
        if (visited[i])
            continue;
        visited[i]=true;
        Dfs(adjPlus,visited,i,segmentVertCount,segmentEdgeCount);
        if (segmentEdgeCount== segmentVertCount*(segmentVertCount-1)) {
            result++;
        }
    }
    return result;
}

void LeetCode2685CountTheNumberOfCompleteComponents::Run() {
    int n=6;
    vector<vector<int>> edges{{0,1},{0,2},{1,2},{3,4}};
    cout<<countCompleteComponents(n,edges)<<endl;
}
