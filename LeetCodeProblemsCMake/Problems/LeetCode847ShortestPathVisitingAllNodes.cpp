//
// Created by saeed on 5/19/25.
//

#include "LeetCode847ShortestPathVisitingAllNodes.h"

#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
int LeetCode847ShortestPathVisitingAllNodes::shortestPathLength( vector< vector<int>> &graph) {
    int length=static_cast<int>(graph.size());
    int maxBitMask=(1<<(length))-1;
    queue<pair<int,int>> currentLayer{};
    queue<pair<int,int>> nextLayer{};
    unordered_map<int,unordered_set<int>> visited{};
    for(int i=0;i<length;i++) {
        currentLayer.emplace(i,1<<i);
        visited[i]={1<<i};
    }
    int cost{};
    int nextMask{};
    while(!currentLayer.empty()) {
        cost++;
        while(!currentLayer.empty()) {
            auto current=currentLayer.front();
            currentLayer.pop();
            for (auto neighbor:graph[current.first]) {
                nextMask=current.second|(1<<neighbor);
                if(nextMask==maxBitMask) {
                    return cost;
                }
                if (visited[neighbor].contains(nextMask)) {
                    continue;
                }
                nextLayer.emplace(neighbor,nextMask);
                visited[neighbor].insert(nextMask);
            }
        }
        while (!nextLayer.empty()) {
            currentLayer.push(nextLayer.front());
            nextLayer.pop();
        }
    }
    return 0;
}
