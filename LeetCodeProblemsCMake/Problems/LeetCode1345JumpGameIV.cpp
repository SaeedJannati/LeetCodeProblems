//
// Created by Saeed Jannati on 5/18/26.
//

#include "LeetCode1345JumpGameIV.h"

#include <queue>
#include <unordered_map>
using namespace std;

int LeetCode1345JumpGameIV::minJumps(vector<int> &arr) {
    int length = static_cast<int>(arr.size());
    unordered_map<int, vector<int> > edges{};
    for (int i = 0; i < length; i++) {
        if (i > 0 && i < length - 1) {
            if (arr[i] == arr[i - 1] && arr[i + 1] == arr[i - 1]) {
                continue;
            }
        }
        if (!edges.contains(arr[i])) {
            edges.insert({arr[i], {}});
        }
        edges[arr[i]].push_back(i);
    }
    vector<bool> visited(length, false);
    queue<int> currentLayer{};
    currentLayer.push(0);
    visited[0] = true;
    queue<int> nextLayer{};
    int node{};
    int step{1};
    int toCheck{};
    while (!currentLayer.empty()) {
        while (!currentLayer.empty()) {
            node = currentLayer.front();
            currentLayer.pop();
            toCheck = node + 1;
            if (toCheck < length) {
                if (toCheck == length - 1)
                    return step;
                if (!visited[toCheck]) {
                    visited[toCheck] = true;
                    nextLayer.push(toCheck);
                }
            }
            toCheck = node - 1;
            if (toCheck >= 0) {
                if (toCheck == length - 1)
                    return step;
                if (!visited[toCheck]) {
                    visited[toCheck] = true;
                    nextLayer.push(toCheck);
                }
            }
            if (edges.contains(arr[node])) {
                for (auto toCheck: edges[arr[node]]) {
                    if (toCheck == length - 1)
                        return step;
                    if (!visited[toCheck]) {
                        visited[toCheck] = true;
                        nextLayer.push(toCheck);
                    }
                }
                edges.erase(arr[node]);
            }
        }
        while (!nextLayer.empty()) {
            currentLayer.push(nextLayer.front());
            nextLayer.pop();
        }
        ++step;
    }
    return length-1;
}
