//
// Created by saeed on 5/28/25.
//

#include "LeetCode3372MaximizeTheNumberOfTargetNodesAfterConnectingTreesI.h"

#include <queue>
#include <unordered_map>

#include "../Auxilary/Auxilaries.h"
using namespace std;

vector<int> LeetCode3372MaximizeTheNumberOfTargetNodesAfterConnectingTreesI::maxTargetNodes
(vector<vector<int> > &edges1, vector<vector<int> > &edges2, int k) {
    int n = static_cast<int>(edges1.size()+1);
    vector<int> result(n,1);
    if (k==0)
        return result;
    int m = static_cast<int>(edges2.size()+1);
    unordered_map<int,vector<int>> adjPlusFirst{};
    for (auto & edge : edges1) {
        if (!adjPlusFirst.contains(edge[0])) {
            adjPlusFirst[edge[0]]={};
        }
        adjPlusFirst[edge[0]].push_back(edge[1]);
        if (!adjPlusFirst.contains(edge[1])) {
            adjPlusFirst[edge[1]]={};
        }
        adjPlusFirst[edge[1]].push_back(edge[0]);
    }

    unordered_map<int,vector<int>> adjPlusSecond{};
    for (auto & edge : edges2) {
        if (!adjPlusSecond.contains(edge[0])) {
            adjPlusSecond[edge[0]]={};
        }
        adjPlusSecond[edge[0]].push_back(edge[1]);
        if (!adjPlusSecond.contains(edge[1])) {
            adjPlusSecond[edge[1]]={};
        }
        adjPlusSecond[edge[1]].push_back(edge[0]);
    }
    vector<int> firstGraphTargetCount(n, 1);

    auto visitedLength = std::max(n, m);
    vector<bool> visited(visitedLength, false);
    int counter = 0;
    queue<int> currentLayer = {};
    queue<int> nextLayer = {};
    for (int i = 0; i < n; i++) {
        visited = vector<bool>(visitedLength, false);
        currentLayer = {};
        nextLayer = {};
        currentLayer.push(i);
        visited[i] = true;
        counter=0;
        for (int i = 0; i < k; i++) {
                while (!currentLayer.empty()) {
                    auto node = currentLayer.front();
                    currentLayer.pop();
                    counter++;
                    for (auto neighbor : adjPlusFirst[node]) {
                        if (visited[neighbor])
                            continue;
                        visited[neighbor] = true;
                        nextLayer.push(neighbor);
                    }
                }
                while (!nextLayer.empty()) {
                    auto node = nextLayer.front();
                    nextLayer.pop();
                    currentLayer.emplace(node);
                }
        }
        counter+=currentLayer.size();
        firstGraphTargetCount[i]=counter;
    }
    int maxCount=0;
    for (int i = 0; i < m; i++) {
        visited = vector<bool>(visitedLength, false);
        currentLayer = {};
        nextLayer = {};
        currentLayer.push(i);
        visited[i] = true;
        counter=0;
        for (int i = 0; i < k-1; i++) {
            while (!currentLayer.empty()) {
                auto node = currentLayer.front();
                currentLayer.pop();
                counter++;
                for (auto neighbor : adjPlusSecond[node]) {
                    if (visited[neighbor])
                        continue;
                    visited[neighbor] = true;
                    nextLayer.push(neighbor);
                }
            }
            while (!nextLayer.empty()) {
                auto node = nextLayer.front();
                nextLayer.pop();
                currentLayer.emplace(node);
            }
        }
        counter+=currentLayer.size();
        if (counter>maxCount)
            maxCount = counter;
    }
    for (int i=0;i<n;i++) {
        result[i]=firstGraphTargetCount[i]+maxCount;
    }
    return result;
}

void LeetCode3372MaximizeTheNumberOfTargetNodesAfterConnectingTreesI::Run() {
    vector<vector<int> > edges1 = {{0,1},{0,2},{2,3},{2,4}};
    vector<vector<int> > edges2 = {{0,1},{0,2},{0,3},{2,7},{1,4},{4,5},{4,6}};
    int k = 2;
    Auxilaries::PrintVector(maxTargetNodes(edges1, edges2, k));
}
