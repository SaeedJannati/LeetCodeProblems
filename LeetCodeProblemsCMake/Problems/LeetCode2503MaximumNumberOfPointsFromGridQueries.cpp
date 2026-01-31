//
// Created by saeed on 3/29/25.
//

#include "LeetCode2503MaximumNumberOfPointsFromGridQueries.h"

#include <algorithm>
#include <ostream>
#include <queue>

#include "../Auxilary/Auxilaries.h"
using namespace std;

vector<int> LeetCode2503MaximumNumberOfPointsFromGridQueries::maxPoints(vector<vector<int> > &grid,
                                                                        vector<int> &queries) {
    vector<pair<int, int> > directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int queryLength = static_cast<int>(queries.size());
    int height = static_cast<int>(grid.size());
    int width = static_cast<int>(grid[0].size());
    vector<vector<bool> > visited(height, vector<bool>(width, false));
    vector<pair<int, int> > queriesSorted{};
    queriesSorted.reserve(queries.size());
    for (int i = 0; i < queryLength; i++) {
        queriesSorted.emplace_back(queries[i], i);
    }
    ranges::sort(queriesSorted, [](const auto &x, const auto &y) {
        return x.first < y.first;
    });
    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<> > minHeap{};
    if (grid[0][0] > queriesSorted[queryLength - 1].first) {
        return vector<int>(queryLength, 0);
    }
    minHeap.emplace(grid[0][0], make_pair(0, 0));
    visited[0][0] = true;
    int score{};
    int row{};
    int col{};
    for (auto &query: queriesSorted) {
        while (!minHeap.empty() && minHeap.top().first < query.first) {
            auto element = minHeap.top();
            minHeap.pop();
            score++;
            for (auto &direction: directions) {
                row = element.second.first + direction.first;
                if (row < 0 || row >= height)
                    continue;
                col = element.second.second + direction.second;
                if (col < 0 || col >= width)
                    continue;
                if (visited[row][col])
                    continue;
                visited[row][col] = true;
                minHeap.emplace(grid[row][col], make_pair(row, col));
            }
        }
        queries[query.second]=score;
    }
    return queries;
}

void LeetCode2503MaximumNumberOfPointsFromGridQueries::Run() {
    vector<vector<int> > grid{{1, 2, 3}, {2, 5, 7}, {3, 5, 1}};
    vector<int> queries{5, 6, 2};
    Auxilaries::PrintVector(maxPoints(grid, queries));
}
