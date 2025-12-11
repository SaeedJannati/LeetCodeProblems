//
// Created by saeed on 12/11/25.
//

#include "LeetCode3531CountCoveredBuildings.h"

#include <limits.h>
using namespace std;

int LeetCode3531CountCoveredBuildings::countCoveredBuildings(int n, vector<vector<int> > &buildings) {
    vector<int> maxPerRow(n + 1, INT_MIN);
    vector<int> minPerRow(n + 1, INT_MAX);
    vector<int> maxPerCol(n + 1, INT_MIN);
    vector<int> minPerCol(n + 1, INT_MAX);
    for (auto &building: buildings) {
        maxPerRow[building[0]] = max(maxPerRow[building[0]], building[1]);
        minPerRow[building[0]] = min(minPerRow[building[0]], building[1]);
        maxPerCol[building[1]] = max(maxPerCol[building[1]], building[0]);
        minPerCol[building[1]] = min(minPerCol[building[1]], building[0]);
    }
    int result = 0;
    for (auto &building: buildings) {
        if (building[1]<maxPerRow[building[0]] &&
            building[1]>minPerRow[building[0]] &&
            building[0]<maxPerCol[building[1]] &&
            building[0]>minPerCol[building[1]] ) {
            ++result;
        }
    }
    return result;
}
