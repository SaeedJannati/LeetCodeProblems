//
// Created by Saeed Jannati on 4/27/2026 A.
//

#include "LeetCode1391CheckIfThereIsAValidPathInAGrid.h"

#include <iostream>
#include <ostream>
#include <unordered_map>
using namespace std;

enum Direction {
    Up = 0,
    Left = 1,
    Right = 2,
    Bottom = 3
};

bool dfs(vector<vector<int> > &grid, vector<unordered_map<Direction, Direction> > &roadMap,
         unordered_map<Direction, pair<pair<int, int>, Direction> > &transactions, vector<vector<bool> > &visited,
         int width, int height, int row, int col, Direction incomingDir) {
    if (visited[row][col]) {
        return false;
    }
    if (!roadMap[grid[row][col] - 1].contains(incomingDir)) {
        return false;
    }
    if (row == height && col == width) {
        return true;
    }
    auto dir = transactions[roadMap[grid[row][col] - 1][incomingDir]];

    auto newRow = row + dir.first.first;
    if (newRow < 0 || newRow > height)
        return false;
    auto newCol = col + dir.first.second;
    if (newCol < 0 || newCol > width)
        return false;
    visited[row][col] = true;
    return dfs(grid, roadMap, transactions, visited, width, height, newRow, newCol, dir.second);
}

bool LeetCode1391CheckIfThereIsAValidPathInAGrid::hasValidPath(vector<vector<int> > &grid) {
    int height = static_cast<int>(grid.size()) - 1;
    int width = static_cast<int>(grid[0].size()) - 1;

    vector<unordered_map<Direction, Direction> > roadMap{
        {{Left, Right}, {Right, Left}},
        {{Up, Bottom}, {Bottom, Up}},
        {{Left, Bottom}, {Bottom, Left}},
        {{Bottom, Right}, {Right, Bottom}},
        {{Left, Up}, {Up, Left}},
        {{Up, Right}, {Right, Up}}
    };

    unordered_map<Direction, pair<pair<int, int>, Direction> > transactions{
        {Up, {{-1, 0}, Bottom}},
        {Left, {{0, -1}, Right}},
        {Right, {{0, 1}, Left}},
        {Bottom, {{1, 0}, Up}}
    };
    unordered_map<Direction, Direction> startPoint = roadMap[grid[0][0] - 1];
    for (pair<Direction, Direction> p: startPoint) {
        vector<vector<bool> > visited(height + 1, vector<bool>(width + 1, false));
        if (dfs(grid, roadMap, transactions, visited, width, height, 0, 0, p.first))
            return true;
    }
    return false;
}

void LeetCode1391CheckIfThereIsAValidPathInAGrid::Run() {
    vector<vector<int> > grid{{2, 4, 3}, {6, 5, 2}};
    cout << hasValidPath(grid) << endl;
}
