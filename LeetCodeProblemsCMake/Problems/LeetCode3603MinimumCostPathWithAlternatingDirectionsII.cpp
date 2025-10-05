//
// Created by saeed on 10/5/25.
//

#include "LeetCode3603MinimumCostPathWithAlternatingDirectionsII.h"

#include <climits>
#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

long long LeetCode3603MinimumCostPathWithAlternatingDirectionsII::minCost(int m, int n, vector<vector<int> > &waitCost) {
    vector<vector<long long> > distances(m, vector<long long>(n,  LLONG_MAX));
    distances[0][0] = 0;
    priority_queue<
        pair<long long, pair<int, int> >,
        vector<pair<long long, pair<int, int> > >,
        greater<pair<long long, pair<int, int> > >
    > dijkstraHeap{};
    unordered_set<int> visited{};
    dijkstraHeap.push({1, {0, 0}});
    vector<pair<int, int> > directions{{0, 1},{1, 0}};
    while (!dijkstraHeap.empty()) {
        auto top = dijkstraHeap.top();
        dijkstraHeap.pop();
        int index = top.second.first * n + top.second.second;
        if (visited.contains(index))
            continue;
        visited.insert(index);
        for (auto &dir: directions) {
            int newRow = top.second.first + dir.first;
            if (newRow < 0 || newRow >= m)
                continue;
            int newCol = top.second.second + dir.second;
            if (newCol < 0 || newCol >= n)
                continue;
            int newIndex=newRow * n + newCol;
            if (visited.contains(newIndex))
                continue;
            long long newCost = top.first +(newRow+1)*(newCol+1);
            if (newRow!=m-1 || newCol!=n-1)
                newCost+=waitCost[newRow][newCol];
            if (newCost<distances[newRow][newCol]) {
                distances[newRow][newCol] = newCost;
                dijkstraHeap.push({newCost, {newRow, newCol}});
            }
        }
    }
    return distances[m-1][n-1];
}

void LeetCode3603MinimumCostPathWithAlternatingDirectionsII::Run() {
   int m=2;
       // 1;
    int n=2;
        // 2;
    vector<vector<int> > waitCost{{3,5},{2,4}};
    cout<<minCost(m,n,waitCost)<<endl;
}
