//
// Created by Saeed Jannati on 5/17/2026 AD.
//

#include "LeetCode1306JumpGameIII.h"

#include <queue>
using namespace std;

bool LeetCode1306JumpGameIII::canReach(vector<int> &arr, int start) {
    if (arr[start] == 0) {
        return true;
    }
    int length = static_cast<int>(arr.size());
    vector<bool> visited(length);
    visited[start] = true;
    queue<int> queue{};
    queue.push(start);
    int next{};
    while (!queue.empty()) {
        int index = queue.front();
        queue.pop();
        for (int i = -1; i < 2; i = i + 2) {
            next=index+i*arr[index];
            if (next<0)
                continue;
            if (next>=length)
                continue;
            if (visited[next])
                continue;
            if (arr[next] == 0)
                return true;
            visited[next] = true;
            queue.push(next);
        }
    }
    return false;
}