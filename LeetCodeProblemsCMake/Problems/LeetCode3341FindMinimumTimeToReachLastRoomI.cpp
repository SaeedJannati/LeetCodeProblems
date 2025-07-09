//
// Created by saeed on 5/7/25.
//

#include "LeetCode3341FindMinimumTimeToReachLastRoomI.h"

#include <iostream>
#include <limits>
#include <ostream>
#include <queue>
#include <unordered_set>
using namespace std;

int LeetCode3341FindMinimumTimeToReachLastRoomI::minTimeToReach(vector<vector<int> > &moveTime) {
    unordered_set<int> calculated{};
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> dijkstraHeap{};
    int height = static_cast<int>(moveTime.size());
    int width = static_cast<int>(moveTime[0].size());
    auto distances = vector<vector<int> >(height , vector<int>(width , numeric_limits<int>::max()));
    distances[0][0] = 0;
    dijkstraHeap.emplace(0, 0);
    vector<pair<int,int>> directoins={{0,1},{0,-1},{1,0},{-1,0}};
    int currentWidth{};
    int currentHeight{};
    int newHeight{};
    int newWidth{};
    while(!dijkstraHeap.empty()) {
        auto currentNode = dijkstraHeap.top();
        dijkstraHeap.pop();
        if (calculated.contains(currentNode.second))
            continue;
        calculated.insert(currentNode.second);
        currentHeight=currentNode.second/width;
        currentWidth=currentNode.second%width;
        for ( auto & direction : directoins) {
            newHeight=currentHeight+direction.first;
            if(newHeight<0 || newHeight>=height)
                continue;
            newWidth=currentWidth+direction.second;
            if (newWidth<0 || newWidth>=width)
                continue;
            int time=max(currentNode.first,moveTime[newHeight][newWidth]);
            time++;
            if (time > distances[newHeight][newWidth])
                continue;
            distances[newHeight][newWidth]=time;
            dijkstraHeap.emplace(time, newHeight*width + newWidth);
        }
    }
    return distances[height-1][width-1];
}

void LeetCode3341FindMinimumTimeToReachLastRoomI::Run() {
    vector<vector<int> > moveTime{{0,4},{4,4}};
    cout<<minTimeToReach(moveTime)<<endl;
}
