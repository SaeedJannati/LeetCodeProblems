//
// Created by saeed on 2/12/26.
//

#include "LeetCode3713LongestBalancedSubstringI.h"

#include <vector>
using namespace std;

int LeetCode3713LongestBalancedSubstringI::longestBalanced(string s) {
    int length = static_cast<int>(s.length());
    int maxLength{1};
    int target{0};
    bool balanced{false};
    for (int i = 0; i < length; ++i) {
        auto occurrences = vector<int>(26);
        for (int j = i; j < length; ++j) {
            target = ++occurrences[s[j] - 'a'];
            balanced = true;
            for (auto num: occurrences) {
                if (num == 0) {
                    continue;
                }
                if (num != target) {
                    balanced = false;
                    break;
                }
            }
            if (balanced) {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }
    return maxLength;
}
