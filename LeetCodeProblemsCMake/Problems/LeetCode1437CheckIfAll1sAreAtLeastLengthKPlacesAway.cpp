//
// Created by saeed on 11/17/25.
//

#include "LeetCode1437CheckIfAll1sAreAtLeastLengthKPlacesAway.h"
using namespace std;
bool LeetCode1437CheckIfAll1sAreAtLeastLengthKPlacesAway::kLengthApart( vector<int> &nums, int k) {
    int distance{k};
    for (auto num:nums) {
        if (num==1) {
            if (distance<k)
                return false;
            distance=0;
            continue;
        }
        ++distance;
    }
    return true;
}
