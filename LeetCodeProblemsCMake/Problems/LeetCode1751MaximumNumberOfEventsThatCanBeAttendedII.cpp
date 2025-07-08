//
// Created by saeed on 7/8/25.
//

#include "LeetCode1751MaximumNumberOfEventsThatCanBeAttendedII.h"

#include <algorithm>

using namespace std;

int calculate(vector<vector<int> > &events, vector<vector<int> > &memoisation, int k, int length, int chosenEventCount,
              int index) {
    if (chosenEventCount >= k)
        return 0;
    if (index >= length)
        return 0;
    if (memoisation[index][chosenEventCount] != -1)
        return memoisation[index][chosenEventCount];
    int endDay = events[index][1];
    int begin = index + 1;
    int end = length - 1;
    int mid{};
    int found = length;
    while (begin <= end) {
        mid = (begin + end) / 2;
        if (events[mid][0] > endDay) {
            found = mid;
            end = mid - 1;
            continue;
        }
        begin = mid + 1;
    }
    int pick = events[index][2];
    if (found < length) {
        pick += calculate(events, memoisation, k, length, chosenEventCount + 1, found);
    }
    int skip = calculate(events, memoisation, k, length, chosenEventCount, index + 1);
    memoisation[index][chosenEventCount] = std::max(skip, pick);
    return memoisation[index][chosenEventCount];
}

int LeetCode1751MaximumNumberOfEventsThatCanBeAttendedII::maxValue(vector<vector<int> > &events, int k) {
    ranges::sort(events, [](const vector<int> &a, const vector<int> &b) {
        return a[0] < b[0];
    });
    int length = events.size();
    vector<vector<int> > memoisation(length, vector<int>(k + 1, -1));
    return calculate(events, memoisation, k, length, 0, 0);
}
