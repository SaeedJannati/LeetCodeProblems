//
// Created by saeed on 1/23/25.
//

#include "LeetCode1267CountServersThatCommunicate.h"

#include <unordered_map>


int LeetCode1267CountServersThatCommunicate::countServers(std::vector<std::vector<int> > &grid) {
    int connectedNodes = 0;
    int height = grid.size();
    int width = grid[0].size();
    std::pmr::unordered_map<int, std::vector<std::pair<int, int> > > rows;
    std::pmr::unordered_map<int, std::vector<std::pair<int, int> > > cols;
    std::vector<std::pair<int, int> > directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (grid[i][j] != 1)
                continue;
            if (!rows.contains(i)) {
                rows[i] = std::vector<std::pair<int, int> >();
            }
            rows[i].emplace_back(i, j);
            if (!cols.contains(j))
                cols[j] = std::vector<std::pair<int, int> >();
            cols[j].emplace_back(i, j);
        }
    }
    for (int i = 0; i < height; i++) {
        if (!rows.contains(i))
            continue;
        if (rows[i].size() < 2)
            continue;
        for (const auto& coord : rows[i]) {
            grid[coord.first][coord.second] = -1;
            connectedNodes++;
        }
    }
    for (int i = 0; i < width; i++) {
        if (!cols.contains(i))
            continue;
        if (cols[i].size() < 2)
            continue;
        for (const auto& coord : cols[i]) {
            if (grid[coord.first][coord.second] == -1)
                continue;
            grid[coord.first][coord.second] = -1;
            connectedNodes++;
        }
    }
    return connectedNodes;
}
