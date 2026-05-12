//
// Created by Saeed Jannati on 5/12/2026 AD.
//

#include "LeetCode1665MinimumInitialEnergyToFinishTasks.h"
using namespace std;

int LeetCode1665MinimumInitialEnergyToFinishTasks::minimumEffort(vector<vector<int> > &tasks) {
    ranges::sort(tasks,  [](const vector<int>& a, const vector<int>& b) {
        if (a[1]-a[0]!=b[1]-b[0]) {
            return a[1]-a[0]>b[1]-b[0];
        }
        return  a[1]>b[1];
    });
    int used{},delta{},current{};
    for (auto & task : tasks) {
        if (current<task[1]) {
            delta=task[1]-current;
            current+=delta;
            used+=delta;
        }
        current-=task[0];
    }
    return used;
}
