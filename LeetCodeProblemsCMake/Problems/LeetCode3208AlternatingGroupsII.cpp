//
// Created by saeed on 3/9/25.
//

#include "LeetCode3208AlternatingGroupsII.h"

#include <iostream>
#include <ostream>

int LeetCode3208AlternatingGroupsII::numberOfAlternatingGroups(std::vector<int> &colors, int k) {
    for (int i = 0; i < k - 1; i++) {
        colors.push_back(colors[i]);
    }
    int firstPointer = 0;
    int secondPointer = 1;
    int length = static_cast<int>(colors.size());
    int groupCount = 0;
    while (secondPointer < length ) {
        if (colors[secondPointer] == colors[secondPointer - 1]) {
            secondPointer++;
            if (secondPointer==length)
                break;
            firstPointer = secondPointer - 1;
            continue;
        }
        if (secondPointer - firstPointer < k - 1) {
            secondPointer++;
            if (secondPointer==length)
                break;
            continue;
        }
        groupCount++;
        firstPointer++;
    }
    return groupCount;
}

void LeetCode3208AlternatingGroupsII::Run() {
    std::vector<int> colors{0,1,1};
    int k = 3;
    std::cout << numberOfAlternatingGroups(colors, k) << std::endl;
}
