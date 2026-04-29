//
// Created by Saeed Jannati on 4/29/2026 A.
//

#include "LeetCode1559DetectCyclesIn2DGrid.h"

#include <unordered_set>
using namespace std;

void dfs(vector<vector<char> > &grid, vector<vector<bool> > &visited, vector<pair<int, int> > &directions,
         unordered_set<int> &inPath, bool &found, int height, int width, int lastRow, int lastCol, int row, int col) {
    if (found)
        return;
    int newRow, newCol;
    for (auto dir: directions) {
        newRow = row + dir.first;
        if (newRow < 0 || newRow >= height)
            continue;
        newCol = col + dir.second;
        if (newCol < 0 || newCol >= width)
            continue;
        if (newRow == lastRow && newCol == lastCol)
            continue;
        if (grid[newRow][newCol] !=grid[row][col] )
            continue;
        if (visited[newRow][newCol]) {
            if (inPath.contains(newRow * width + newCol)) {
                found = true;
                return;
            }
            continue;
        }
        visited[newRow][newCol] = true;
        inPath.insert(newRow * width + newCol);
        dfs(grid, visited, directions, inPath, found, height, width, row, col, newRow, newCol);
        inPath.erase(newRow * width + newCol);
    }
}

bool LeetCode1559DetectCyclesIn2DGrid::containsCycle(vector<vector<char> > &grid) {
    int height = static_cast<int>(grid.size());
    int width = static_cast<int>(grid[0].size());
    vector<vector<bool> > visited(height, vector<bool>(width, false));
    vector<pair<int, int> > directions{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    bool found = false;
    unordered_set<int> inPath{};
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (visited[i][j])
                continue;
            visited[i][j] = true;
            inPath.insert(i * width + j);
            dfs(grid, visited, directions, inPath, found, height, width, i, j, i, j);
            inPath.erase(i * width + j);
            if (found)
                return true;
        }
    }
    return false;
}
