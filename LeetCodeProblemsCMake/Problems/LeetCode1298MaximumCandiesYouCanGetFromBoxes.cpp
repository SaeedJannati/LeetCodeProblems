//
// Created by saeed on 6/3/25.
//

#include "LeetCode1298MaximumCandiesYouCanGetFromBoxes.h"

#include <queue>
#include <unordered_set>
using namespace std;

int LeetCode1298MaximumCandiesYouCanGetFromBoxes::maxCandies(vector<int> &status, vector<int> &candies,
                                                             vector<vector<int> > &keys,
                                                             vector<vector<int> > &containedBoxes,
                                                             vector<int> &initialBoxes) {
    int maxCandies {};
    vector<bool> visited(status.size(), false);
    unordered_set<int> collectedNotOpenedBoxes{};
    queue<int> boxesToOpen{};
    for (int i = 0; i < initialBoxes.size(); i++) {
        if (status[initialBoxes[i]] == 0) {
            collectedNotOpenedBoxes.insert(initialBoxes[i]);
            continue;
        }
        boxesToOpen.push(initialBoxes[i]);
    }
    while (boxesToOpen.size() > 0) {
        auto box = boxesToOpen.front();
        boxesToOpen.pop();
        if (visited[box])
            continue;
        visited[box] = true;
        maxCandies+=candies[box];
        for (auto key : keys[box]) {
            if (visited[key])
                continue;
            status[key] = 1;
            if (!collectedNotOpenedBoxes.contains(key))
                continue;
            boxesToOpen.push(key);
            collectedNotOpenedBoxes.erase(key);
        }
        for (auto newBox : containedBoxes[box]) {
            if (visited[newBox])
                continue;
            if (collectedNotOpenedBoxes.contains(newBox))
                continue;
            if (status[newBox] == 0) {
                collectedNotOpenedBoxes.insert(newBox);
                continue;
            }
            boxesToOpen.push(newBox);
        }

    }
    return maxCandies;
}
