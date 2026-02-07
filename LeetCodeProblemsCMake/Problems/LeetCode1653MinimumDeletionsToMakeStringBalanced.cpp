//
// Created by Saeed Jannati on 2/7/2026 A.
//

#include "LeetCode1653MinimumDeletionsToMakeStringBalanced.h"

using namespace std;

int LeetCode1653MinimumDeletionsToMakeStringBalanced::minimumDeletions(string s) {
    int length = s.length();
    int aAfter{};
    int bBefore{};
    for (auto c: s) {
        if (c == 'a') {
            aAfter++;
        }
    }
    int toRemove{};
    int minToRemove{length};
    for (auto c: s) {
        if (c == 'a') {
            aAfter--;
        }
        toRemove = aAfter + bBefore;
        minToRemove = min(minToRemove, toRemove);
        if (c == 'b') {
            bBefore++;
        }
    }
    return minToRemove;
}
