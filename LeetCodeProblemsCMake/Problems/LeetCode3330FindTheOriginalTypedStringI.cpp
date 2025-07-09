//
// Created by saeed on 7/1/25.
//

#include "LeetCode3330FindTheOriginalTypedStringI.h"

using namespace std;

int LeetCode3330FindTheOriginalTypedStringI::possibleStringCount(string word) {
    char previous{0};
    int streak{0};
    int possibleStringCount{1};
    for (auto letter: word) {
        if (letter == previous) {
            streak++;
            continue;
        }
        previous = letter;
        if (streak > 1) {
            possibleStringCount += (streak - 1);
        }
        streak = 1;
    }
    if (streak > 1) {
        possibleStringCount += (streak - 1);
    }
    return possibleStringCount;
}
