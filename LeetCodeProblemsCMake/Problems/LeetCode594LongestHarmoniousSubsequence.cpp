//
// Created by saeed on 6/30/25.
//

#include "LeetCode594LongestHarmoniousSubsequence.h"

#include <unordered_map>
using namespace std;

int LeetCode594LongestHarmoniousSubsequence::findLHS(vector<int> &nums) {
    unordered_map<int, int> map{};
    for (auto num: nums) {
        map[num]++;
    }
    int result{0};
    int current{0};
    for (auto &pair: map) {
        current = pair.second;
        if (!map.contains(pair.first + 1))
            continue;
        current += map[pair.first + 1];
        if (current > result) {
            result = current;
        }
    }
    return result;
}
