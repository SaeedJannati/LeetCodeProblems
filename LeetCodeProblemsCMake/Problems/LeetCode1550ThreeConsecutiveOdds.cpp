//
// Created by saeed on 5/11/25.
//

#include "LeetCode1550ThreeConsecutiveOdds.h"

bool LeetCode1550ThreeConsecutiveOdds::threeConsecutiveOdds(std::vector<int> &arr) {
    int consecutiveOdds{};
    for (auto num : arr) {
        if (num % 2 == 0) {
            consecutiveOdds ++;
            if (consecutiveOdds ==3) {
                return true;
            }
            continue;
        }
        consecutiveOdds = 0;
    }
    return false;
}


