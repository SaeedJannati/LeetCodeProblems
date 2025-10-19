//
// Created by saeed on 10/19/25.
//

#include "LeetCode1625LexicographicallySmallestStringAfterApplyingOperations.h"

#include <algorithm>
#include <queue>
#include <unordered_set>
using namespace std;

string LeetCode1625LexicographicallySmallestStringAfterApplyingOperations::findLexSmallestString(string s, int a, int b) {
    unordered_set<string> visited{};
    queue<string> toCheck{};
    toCheck.push(s);
    visited.insert(s);
    int length = s.length();
    string smallest{s};
    while (!toCheck.empty()) {
        auto top = toCheck.front();
        toCheck.pop();
        string rotated{top};
        for (int i = 0; i < length; i++) {
            rotated[i]=top[i-b>=0?i-b:length+i-b];
        }
        if (!visited.contains(rotated)) {
            visited.insert(rotated);
            toCheck.push(rotated);
            if (rotated<smallest)
                smallest=rotated;
        }
        string moved{top};
        for (int i=1;i<length;i=i+2) {
            moved[i]=static_cast<char>(((moved[i] - '0' + a) % 10) + '0');
        }
        if (!visited.contains(moved)) {
            visited.insert(moved);
            toCheck.push(moved);
            if (moved<smallest) {
                smallest=moved;
            }
        }

    }
    return smallest;
}
