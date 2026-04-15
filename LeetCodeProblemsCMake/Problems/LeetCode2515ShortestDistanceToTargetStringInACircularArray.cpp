//
// Created by Saeed Jannati on 4/15/2026 A.
//

#include "LeetCode2515ShortestDistanceToTargetStringInACircularArray.h"

#include <iostream>
#include <ostream>
using namespace std;

int LeetCode2515ShortestDistanceToTargetStringInACircularArray::closestTarget(vector<string> &words,
                                                                              string target, int startIndex) {
    int length = static_cast<int>(words.size());
    if (words[startIndex] == target) {
        return 0;
    }
    int upIndex{startIndex + 1};
    if (upIndex >= length) {
        upIndex = 0;
    }
    int downIndex{startIndex - 1};
    if (downIndex < 0) {
        downIndex = length - 1;
    }
    int step{1};
    while (upIndex != startIndex || downIndex != startIndex) {
        if (upIndex != startIndex && words[upIndex] == target) {
            return step;
        }
        if (downIndex != startIndex && words[downIndex] == target) {
            return step;
        }
        if (upIndex != startIndex) {
            ++upIndex;
            if (upIndex >= length) {
                upIndex = 0;
            }
        }
        if (downIndex != startIndex) {
            --downIndex;
            if (downIndex < 0) {
                downIndex = length - 1;
            }
        }
        ++step;
    }
    return -1;
}

void LeetCode2515ShortestDistanceToTargetStringInACircularArray::Run() {
    vector<string> words = {"hello", "i", "am", "leetcode", "hello"};
    string target{"hello"};
    int startIndex{1};
    cout << closestTarget(words, target, startIndex) << '\n';
}
