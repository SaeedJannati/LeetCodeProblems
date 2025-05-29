//
// Created by saeed on 5/29/25.
//

#include "LeetCode3373MaximizeTheNumberOfTargetNodesAfterConnectingTreesII.h"

#include <unordered_map>

#include "../Auxilary/Auxilaries.h"
using namespace std;

void FillAdjPlus(vector<vector<int> > &edges, unordered_map<int, vector<int> > &adjplus) {
    for (auto &edge: edges) {
        if (!adjplus.contains(edge[0])) {
            adjplus[edge[0]] = {};
        }
        adjplus[edge[0]].push_back(edge[1]);
        if (!adjplus.contains(edge[1])) {
            adjplus[edge[1]] = {};
        }
        adjplus[edge[1]].push_back(edge[0]);
    }
}

void Dfs(unordered_map<int, vector<int> > &adjPlus, vector<bool> &visited, vector<int> &colours,
         vector<int> &coloursCount, int node, int colour) {
    auto colourNext = colour == 0 ? 1 : 0;
    for (auto neighbour: adjPlus[node]) {
        if (visited[neighbour])
            continue;
        visited[neighbour] = true;
        colours[neighbour] = colour;
        coloursCount[colour]++;

        Dfs(adjPlus, visited, colours, coloursCount, neighbour, colourNext);
    }
}

vector<int> LeetCode3373MaximizeTheNumberOfTargetNodesAfterConnectingTreesII::maxTargetNodes(
    vector<vector<int> > &edges1, vector<vector<int> > &edges2) {
    unordered_map<int, vector<int> > adjPlusFirst{};
    unordered_map<int, vector<int> > adjPlusSecond{};
    int n = static_cast<int>(edges1.size()) + 1;
    int m = static_cast<int>(edges2.size()) + 1;
    int visitedLength = std::max(n, m);
    vector<bool> visited(visitedLength, false);
    FillAdjPlus(edges1, adjPlusFirst);
    FillAdjPlus(edges2, adjPlusSecond);
    vector<int> firstColours(n, 0);
    vector<int> firstColourCount(2, 0);
    vector<int> secondColours(m, 0);
    vector<int> secondColourCount(2, 0);
    visited[0] = true;
    firstColours[0]=0;
    firstColourCount[0]=1;
    Dfs(adjPlusFirst,visited,firstColours,firstColourCount,0,1);
    visited=vector<bool>(m, false);
    visited[0] = true;
    secondColours[0]=0;
    secondColourCount[0]=1;
    Dfs(adjPlusSecond,visited,secondColours,secondColourCount,0,1);
    int maxCountSecond=std::max(secondColourCount[0],secondColourCount[1]);
    vector<int> result(n,0);
    for(int i=0;i<n;i++) {
         result[i]=firstColourCount[ firstColours[i]]+maxCountSecond;
    }
    return result;
}

void LeetCode3373MaximizeTheNumberOfTargetNodesAfterConnectingTreesII::Run() {
    vector<vector<int>> edges1{{0,1},{0,2},{2,3},{2,4}};
    vector<vector<int>> edges2{{0,1},{0,2},{0,3},{2,7},{1,4},{4,5},{4,6}};
    Auxilaries::PrintVector(maxTargetNodes(edges1, edges2));
}
