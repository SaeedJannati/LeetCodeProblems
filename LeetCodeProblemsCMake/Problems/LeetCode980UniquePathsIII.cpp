//
// Created by saeed on 1/18/25.
//

#include "LeetCode980UniquePathsIII.h"

#include <iostream>
#include <ostream>

void BackTrack(std::vector<std::vector<int> > &grid, std::vector<std::vector<bool> > &visited,
               std::vector<std::pair<int, int> > &directions, int &result, int height, int width, int row, int col,
               int pathLength, int desiredPathLength) {
    visited[row][col] = true;
    int newRow = row;
    int newCol = col;
    for (int i = 0; i < 4; i++) {
        newRow = row + directions[i].first;
        if (newRow < 0 || newRow >= height)
            continue;
        newCol = col + directions[i].second;
        if (newCol < 0 || newCol >= width)
            continue;
        if (visited[newRow][newCol])
            continue;
        if (grid[newRow][newCol] == -1) {
            continue;
        }
        if (grid[newRow][newCol] == 2) {
            if (pathLength + 1 == desiredPathLength)
                result++;
            continue;
        }
        BackTrack(grid, visited, directions, result, height, width, newRow, newCol,pathLength+1,desiredPathLength);
    }
    visited[row][col] = false;
}

int LeetCode980UniquePathsIII::uniquePathsIII(std::vector<std::vector<int> > &grid) {
    int height = grid.size();
    int width = grid[0].size();
    std::vector<std::pair<int, int> > directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    std::vector visited(height, std::vector(width, false));
    int row = 0;
    int col = 0;
    int pathLength{1};
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++) {
            if (grid[i][j] == 0) { pathLength++; }
            if (grid[i][j] == 1) {
                visited[i][j] = true;
                row = i;
                col = j;
            }
        }
    int result = 0;
    BackTrack(grid, visited, directions, result, height, width, row, col, 0, pathLength);
    return result;
}

void LeetCode980UniquePathsIII::Run() {
    std::vector<std::vector<int>> grid={{1,0,0,0},{0,0,0,0},{0,0,0,2}};
    std::cout<<uniquePathsIII(grid)<<std::endl;
}
