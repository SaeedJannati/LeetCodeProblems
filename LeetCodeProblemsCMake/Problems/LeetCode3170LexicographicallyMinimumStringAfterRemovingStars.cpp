//
// Created by saeed on 6/7/25.
//

#include "LeetCode3170LexicographicallyMinimumStringAfterRemovingStars.h"

#include <iostream>
#include <ostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

struct Comparer {
    bool operator()(const pair<char, int> &a, const pair<char, int> &b) {
        return a.first != b.first ? a.first > b.first : a.second < b.second;
    }
};

string LeetCode3170LexicographicallyMinimumStringAfterRemovingStars::clearStars(string s) {
    priority_queue<pair<char, int>, vector<pair<char, int> >, Comparer> minHeap{};
    unordered_set<int> removals{};
    int length = s.length();
    for (auto i = 0; i < length; i++) {
        if (s[i] != '*') {
            minHeap.emplace(s[i], i);
            continue;
        }
        removals.insert(i);
        removals.insert(minHeap.top().second);
        minHeap.pop();
    }
    string result{};
    for (int i=0;i<length;i++) {
        if (removals.contains(i))
            continue;
        result += s[i];
    }
    return result;
}

void LeetCode3170LexicographicallyMinimumStringAfterRemovingStars::Run() {
    const auto s = "y*eekyy*ed***kyd**";
    cout << clearStars(s) << endl;
}
