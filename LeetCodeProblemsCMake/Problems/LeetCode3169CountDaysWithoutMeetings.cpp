//
// Created by saeed on 3/24/25.
//

#include "LeetCode3169CountDaysWithoutMeetings.h"

#include <algorithm>
#include <iostream>
#include <ostream>

using namespace std;

int LeetCode3169CountDaysWithoutMeetings::countDays(int days, std::vector<std::vector<int> > &meetings) {
    int length = static_cast<int>(meetings.size());
    ranges::sort(meetings, [](const std::vector<int> &a, const std::vector<int> &b) { return a[0] < b[0]; });

    vector<vector<int> > meetingsMerged{};

    for (int i = 0; i < length; i++) {
        int begin = meetings[i][0];
        int end = meetings[i][1];
        while (i < length - 1 && end >= meetings[i + 1][0]) {
            end = max(end, meetings[i + 1][1]);
            i++;
        }
        meetingsMerged.push_back({begin, end});
    }
    int result{};
    int mergedLength = static_cast<int>(meetingsMerged.size());
    for (int i = 0; i < mergedLength-1; i++) {
        result+=meetingsMerged[i+1][0]-meetingsMerged[i][1]-1;
    }
    result+=meetingsMerged[0][0]-1;
    result+=max(0,days- meetingsMerged[mergedLength-1][1]);
    return result;
}

void LeetCode3169CountDaysWithoutMeetings::Run() {
    int days =
        // 5;
    10;
    vector<vector<int> > meetings
    // {{2, 4}, {1, 3}};
    {{5,7},{1,3},{9,10}};
    cout << countDays(days, meetings) << endl;
}
