//
// Created by saeed on 7/31/25.
//

#include "LeetCode898BitwiseORsOfSubarrays.h"

#include <unordered_set>
using namespace std;


int LeetCode898BitwiseORsOfSubarrays::subarrayBitwiseORs(vector<int> &arr) {
    unordered_set<int> result{};
    unordered_set<int> current{};
    unordered_set<int> next{};
    for (auto num: arr) {
        next = {};
        next.insert(num);
        for (auto orVal: current) {
            next.insert(orVal | num);
        }
        current = next;
        result.insert(next.begin(), next.end());
    }
    return static_cast<int>( result.size());
}
