//
// Created by saeed on 10/6/25.
//

#include "LeetCode778SwimInRisingWater.h"

#include <limits.h>
#include <queue>
#include <unordered_set>
using namespace std;


int LeetCode778SwimInRisingWater::swimInWater(vector<vector<int> > &grid) {
    int height = grid.size();
    int width = grid[0].size();
    unordered_set<int> visited{};
    vector<pair<int, int> > directions = vector<pair<int, int> >{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    priority_queue<
        pair<int, pair<int, int> >, // element type
        vector<pair<int, pair<int, int> > >, // underlying container
        greater<pair<int, pair<int, int> > > // comparator (min-heap)
    > dijkstraHeap{};
    vector<vector<int> > distances = vector<vector<int> >(height, vector<int>(width, INT_MAX));
    distances[0][0]=grid[0][0];
    dijkstraHeap.push({grid[0][0],{0,0}});
    int index{},newRow{},newCol{},newIndex{},distance{};
    while (!dijkstraHeap.empty()) {
        auto top = dijkstraHeap.top();
        dijkstraHeap.pop();
        index = top.second.first * width + top.second.second;
        if (visited.contains(index))
            continue;
        visited.insert(index);
        for (auto & dir: directions) {
            newRow = top.second.first + dir.first;
            if (newRow < 0 || newRow >= height)
                continue;
            newCol = top.second.second + dir.second;
            if (newCol < 0 || newCol >= width)
                continue;
            newIndex = newRow * width + newCol;
            if (visited.contains(newIndex))
                continue;
            distance=max(grid[newRow][newCol],top.first);
            if (distance>distances[newRow][newCol])
                continue;
            distances[newRow][newCol] = distance;
            dijkstraHeap.push({distance, {newRow, newCol}});
        }
    }
    return distances[height-1][width-1];

}
