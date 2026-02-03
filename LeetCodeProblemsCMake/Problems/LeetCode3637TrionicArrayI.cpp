//
// Created by Saeed Jannati on 2/3/2026 A.
//

#include "LeetCode3637TrionicArrayI.h"
using namespace std;

bool LeetCode3637TrionicArrayI::isTrionic(vector<int> &nums) {
    int previous{nums[0]};
    vector<int> slopes{};
    int slope{};
    int delta{};
    for (int i = 1, e = nums.size(); i < e; i++) {
        delta = nums[i] - previous;
        previous = nums[i];
        if (delta == 0) {
            return false;
        }
        if (slopes.size() == 0) {
            if (delta < 0) {
                return false;
            }
            slopes.push_back(1);
            continue;
        }
        slope = delta > 0 ? 1 : -1;
        if (slope * slopes[slopes.size() - 1] > 0) {
            continue;
        }
        slopes.push_back(slope);
        if (slopes.size() > 3) {
            return false;
        }
    }
    return slopes.size() == 3;
}
