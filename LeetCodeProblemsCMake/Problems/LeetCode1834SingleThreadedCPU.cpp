//
// Created by saeed on 9/25/25.
//

#include "LeetCode1834SingleThreadedCPU.h"

#include <algorithm>
#include <map>
#include <queue>
#include <set>

#include "../Auxilary/Auxilaries.h"
using namespace std;

vector<int> LeetCode1834SingleThreadedCPU::getOrder(vector<vector<int> > &tasks) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > tasksToProcess{};
    long long currentTime{};
    int tasksPointer{0};
    int tasksSize = static_cast<int>(tasks.size());
    vector<int> result{};
    result.reserve(tasksSize);
    for (int i = 0; i < tasksSize; i++) {
        tasks[i].push_back(i);
    }
    ranges::sort(tasks, [](const vector<int> &a, const vector<int> &b) {
        if (a[0]==b[0])
            return a[1]<b[1];
        return a[0] < b[0];
    });
    while (true) {
        if (tasksToProcess.empty()) {
            if (tasksPointer==tasks.size()) {
                return result;
            }
            currentTime= max<long long>(currentTime, tasks[tasksPointer][0]);
        }
        while (tasksPointer<tasksSize && tasks[tasksPointer][0]<=currentTime)
        {
            tasksToProcess.emplace(tasks[tasksPointer][1], tasks[tasksPointer][2]);
            ++tasksPointer;
        }
        auto top = tasksToProcess.top();
        tasksToProcess.pop();
        result.push_back(top.second);
        currentTime += top.first;

    }
    return result;
}

void LeetCode1834SingleThreadedCPU::Run() {
    vector<vector<int> > tasks{{1, 2}, {2, 4}, {3, 2}, {4, 1}};
    Auxilaries::PrintVector(getOrder(tasks));
}
