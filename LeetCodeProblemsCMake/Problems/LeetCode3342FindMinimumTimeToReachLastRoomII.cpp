//
// Created by saeed on 5/8/25.
//

#include "LeetCode3342FindMinimumTimeToReachLastRoomII.h"

#include <limits>
#include <queue>
#include <unordered_set>
using namespace std;
int LeetCode3342FindMinimumTimeToReachLastRoomII::minTimeToReach(vector<vector<int>> &moveTime) {
    int height=static_cast<int>( moveTime.size());
    int width=static_cast<int>( moveTime[0].size());
    vector<vector<int>> distances(height,vector<int>(width,numeric_limits<int>::max()));
    distances[0][0]=0;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>> >,greater<> > dijkstraHeap{};
    dijkstraHeap.push({0,{0,0}});
    unordered_set<int> calculated{};
    vector<pair<int,int>> directions{{0,-1},{0,1},{-1,0},{1,0}};
    int currentHeight{};
    int currentWidth{};
    int newHeight{};
    int newWidth{};
    int time{};
    while(!dijkstraHeap.empty()) {
        auto current=dijkstraHeap.top();
        dijkstraHeap.pop();
        if (calculated.contains(current.second.first))
            continue;
        currentHeight=current.second.first/width;
        currentWidth=current.second.first%width;
        for (const auto & direction:directions) {
            newHeight=currentHeight+direction.first;
            if(newHeight<0 || newHeight>=height)
                continue;
            newWidth=currentWidth+direction.second;
            if (newWidth<0 || newWidth>=width)
                continue;
            time=max(current.first,moveTime[newHeight][newWidth]);
            time+=(current.second.second%2==0?1:2);
            if (time<distances[newHeight][newWidth]) {
                distances[newHeight][newWidth]=time;
                dijkstraHeap.push({time,{newHeight*width+newWidth,current.second.second+1}});
            }
        }
    }
    return distances[height-1][width-1];
}
