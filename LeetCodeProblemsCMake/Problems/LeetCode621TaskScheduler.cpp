//
// Created by saeed on 10/8/25.
//

#include "LeetCode621TaskScheduler.h"

#include <iostream>
#include <ostream>
#include <queue>
#include <unordered_map>
using namespace std;


int LeetCode621TaskScheduler::leastInterval(vector<char> &tasks, int n) {
    priority_queue<pair<int, char>, vector<pair<int, char> >, greater<pair<int, char> > > frequencies;
    priority_queue<pair<int, char> > temp{};
    unordered_map<char, int> charMap{};
    for (auto task: tasks) {
        charMap[task]++;
    }
    for (auto &pair: charMap) {
        frequencies.push({1, pair.first});
    }
    int time{};
    while (!charMap.empty()) {
        auto top = frequencies.top();
        if (temp.empty())
            time = max(time, top.first);
        while (!frequencies.empty() && frequencies.top().first <= time) {
            temp.push({charMap[frequencies.top().second], frequencies.top().second});
            frequencies.pop();
        }
        time++;
        auto toInsert = temp.top();
        temp.pop();

        charMap[toInsert.second]--;
        if (charMap[toInsert.second] == 0) {
            charMap.erase(toInsert.second);
            continue;
        }
        frequencies.push({time + n, toInsert.second});
    }
    return time-1;
}

void LeetCode621TaskScheduler::Run() {
    vector<char> tasks={'A', 'C', 'A', 'B', 'D', 'B'};

        // {'A', 'A', 'A', 'B', 'B', 'B'};
    int n =1;
        // 2;
    cout << leastInterval(tasks, n) << endl;
}
