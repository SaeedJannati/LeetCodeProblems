//
// Created by saeed on 7/11/25.
//

#include "LeetCode2402MeetingRoomsIII.h"

#include <functional>
#include <queue>
#include <algorithm>
#include <iostream>
#include <ostream>
using namespace std;

int LeetCode2402MeetingRoomsIII::mostBooked(int n, vector<vector<int> > &meetings) {
    long currentTime{};
    vector<int> roomUseCount(n,0);
    priority_queue<int, vector<int>, greater<int>> availableRooms{};
    priority_queue<pair<int, long>, vector<pair<int, long>>, function<bool(pair<int, long>, pair<int, long>)>> ocupiedRooms(
        [](const pair<int, long>& a, const pair<int, long>& b) {
            return a.second > b.second;
        }
        );
    ranges::sort(meetings,[](const vector<int>& a, const vector<int>& b) {
        return a[0]<b[0];
    });
    int length=meetings.size();
    for (int i = 0; i < n; i++) {
        availableRooms.push(i);
    }
    int maxUses{};
    int maxUsedIndex{};
    for(int i=0;i<length;i++) {
        currentTime=std::max<long>(currentTime,meetings[i][0]);
        while (!ocupiedRooms.empty() && ocupiedRooms.top().second<=currentTime) {
            auto room=ocupiedRooms.top();
            ocupiedRooms.pop();
            availableRooms.emplace(room.first);
        }
        if (!availableRooms.empty()) {
            auto roomNumber = availableRooms.top();
            availableRooms.pop();
            roomUseCount[roomNumber]++;
            if (roomUseCount[roomNumber] > maxUses) {
                maxUses = roomUseCount[roomNumber];
                maxUsedIndex = roomNumber;
            }
            if (roomUseCount[roomNumber] == maxUses && roomNumber<maxUsedIndex) {
                maxUsedIndex = roomNumber;
            }
            ocupiedRooms.emplace(roomNumber,currentTime-meetings[i][0]+meetings[i][1]);
            continue;
        }
        auto nextRoom=ocupiedRooms.top();
        currentTime=max<long>(nextRoom.second,meetings[i][0]);
        while (!ocupiedRooms.empty() && ocupiedRooms.top().second<=currentTime) {
            auto room=ocupiedRooms.top();
            ocupiedRooms.pop();
            availableRooms.emplace(room.first);
        }
        auto roomNumber = availableRooms.top();
        availableRooms.pop();
        roomUseCount[roomNumber]++;
        if (roomUseCount[roomNumber] > maxUses) {
            maxUses = roomUseCount[roomNumber];
            maxUsedIndex = roomNumber;
        }
        if (roomUseCount[roomNumber] == maxUses && roomNumber<maxUsedIndex) {
            maxUsedIndex = roomNumber;
        }
        ocupiedRooms.emplace(roomNumber,currentTime-meetings[i][0]+meetings[i][1]);
    }
    return  maxUsedIndex;
}

void LeetCode2402MeetingRoomsIII::Run() {
    vector<vector<int>> meetings ={{0,10},{1,9},{2,8},{3,7},{4,6}};
        // {{1,20},{2,10},{3,5},{4,9},{6,8}};
    int n =
        3;
        // 3;
    cout<<mostBooked(n,meetings)<<endl;
}
