//
// Created by saeed on 7/7/25.
//

#include "LeetCode1353MaximumNumberOfEventsThatCanBeAttended.h"

#include <algorithm>
#include <iostream>
#include <ostream>
#include <queue>


using namespace std;

int LeetCode1353MaximumNumberOfEventsThatCanBeAttended::maxEvents(vector<vector<int> > &events) {
    ranges::sort(events, [](const vector<int> &a, const vector<int> &b) {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }
        return a[0] < b[0];
    });
    auto cmp = [](const vector<int> &a, const vector<int> &b) {
        return a[1] > b[1];
    };
    priority_queue<vector<int>, vector<vector<int> >, decltype(cmp)> minHeap(cmp);

    auto length = events.size();
    auto maxDay = events[length - 1][1];

    int eventsCovered{0};
    int j{0};
    for (int i = events[0][0]; i <= maxDay; i++) {
        while (j < length && events[j][0] <= i) {
            if (events[j][1] > maxDay) {
                maxDay = events[j][1];
            }
            minHeap.push(events[j]);
            j++;
        }
        while (!minHeap.empty() && minHeap.top()[1] < i) {
            minHeap.pop();
        }
        if(minHeap.empty())
          continue;
        auto event = minHeap.top();
        minHeap.pop();
        if (i >= event[0] && i <= event[1]) {
            eventsCovered++;
        }
    }

    return eventsCovered;
}

void LeetCode1353MaximumNumberOfEventsThatCanBeAttended::Run() {
    vector<vector<int> > events =
            // {{1, 5}, {1, 5}, {1, 5}, {2, 3}, {2, 3}};
            {{1, 2}, {1, 2}, {3, 3}, {1, 5}, {1, 5}};
    // {{1, 4}, {4, 4}, {2, 2}, {3, 4}, {1, 1}};
    // {{1,2},{1,2},{1,6},{1,2},{1,2}};
    cout << maxEvents(events) << endl;
}
