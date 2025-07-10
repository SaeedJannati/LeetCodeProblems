//
// Created by saeed on 7/10/25.
//

#include "LeetCode3440RescheduleMeetingsForMaximumFreeTimeII.h"

#include <algorithm>
#include <iostream>
#include <ostream>
using namespace std;

int LeetCode3440RescheduleMeetingsForMaximumFreeTimeII::maxFreeTime(int eventTime, vector<int> &startTime,
                                                                    vector<int> &endTime) {
    int length = startTime.size();
    int result{};
    int current{};
    int lastDelay = startTime[0];
    int nextStartTime{};
    vector<pair<int,int>> delays(length+1, make_pair(0, 0));
    delays[0]= make_pair(0, lastDelay);
    for (int i = 0; i < length; i++) {
        current = lastDelay;
        nextStartTime=i<length-1?startTime[i+1]:eventTime;
        lastDelay = nextStartTime - endTime[i];
        delays[i+1] = make_pair(i+1, lastDelay);
        current += lastDelay;
        if (current > result) {
            result = current;
        }
    }
    ranges::sort(delays, [](const pair<int,int>& left, const pair<int,int>& right) {
        return left.second > right.second;
    });
    int eventLength{};
    bool found{};
    int lastEndTime{};

    for (int i = 0; i < length; i++) {
        found = false;
        eventLength=endTime[i] - startTime[i];
        for (int j=0;j<3;j++) {
            if (delays[j].first ==i || delays[j].first ==i+1) {
                continue;
            }
            if (delays[j].second>=eventLength) {
                found = true;
                break;
            }
        }
        if (!found) {
            lastEndTime = endTime[i];
            continue;
        }
        nextStartTime = i<length-1?startTime[i+1]:eventTime;
        current=nextStartTime-lastEndTime;
        if (current > result) {
            result = current;
        }
        lastEndTime = endTime[i];
    }
    return result;
}

void LeetCode3440RescheduleMeetingsForMaximumFreeTimeII::Run() {
    vector<int> startTime={0,17};
    vector<int> endTime={14,19};
    int eventTime=34;
    cout<<maxFreeTime(eventTime, startTime, endTime)<<endl;
}
