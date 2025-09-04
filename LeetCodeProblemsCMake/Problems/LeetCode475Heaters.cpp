//
// Created by saeed on 9/4/25.
//

#include "LeetCode475Heaters.h"

#include <algorithm>
#include <iostream>
#include <limits.h>
using namespace std;

int LeetCode475Heaters::findRadius(vector<int> &houses, vector<int> &heaters) {
    ranges::sort(heaters);
    ranges::sort(houses);
    int maxDistance{INT_MIN};
    int minDistance{};
    int heatersLength = static_cast<int>(heaters.size());
    for (int house: houses) {
        minDistance = INT_MAX;
        int begin{};
        int end{heatersLength-1};
        int mid{};
        while (begin <= end) {
            mid = (begin + end) >> 1;
            if (house == heaters[mid]) {
                break;
            }
            if (house < heaters[mid]) {
                end = mid - 1;
                continue;
            }
            begin = mid + 1;
        }
        if (house == heaters[mid]) {
            minDistance = 0;
        } else {
            minDistance = min(minDistance, abs(house - heaters[mid]));
            if (mid > 0) {
                minDistance = min(minDistance, abs(house - heaters[mid - 1]));
            }
            if (mid < heatersLength-1) {
                minDistance = min(minDistance, abs(house - heaters[mid + 1]));
            }
        }
        maxDistance = max(minDistance, maxDistance);
    }
    return maxDistance;
}

void LeetCode475Heaters::Run() {
    vector<int> houses{1};
    vector<int> heaters{1,2,3,4};
    cout<<findRadius(houses, heaters);
}
