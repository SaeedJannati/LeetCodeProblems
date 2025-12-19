//
// Created by saeed on 12/19/25.
//

#include "LeetCode2092FindAllPeopleWithSecret.h"

#include <algorithm>
#include <unordered_map>
#include <unordered_set>

#include "../Auxilary/Auxilaries.h"
using namespace std;
void dfs(unordered_map<int,unordered_set<int>>& adj,unordered_set<int>& visited,unordered_set<int>& withSecret,int node) {
    for (auto & neighbour:adj[node]) {
        if (visited.contains(neighbour))
            continue;
        visited.insert(neighbour);
        withSecret.insert(neighbour);
        dfs(adj,visited,withSecret,neighbour);
    }
}

vector<int> LeetCode2092FindAllPeopleWithSecret::findAllPeople(int n, vector<vector<int> > &meetings,
                                                               int firstPerson) {
    ranges::sort(meetings, [](vector<int> &a, vector<int> &b) { return a[2] < b[2]; });
    unordered_set<int> withSecret{0, firstPerson};
    vector<int> result{};
    int t{};
    unordered_map<int, unordered_set<int> > adjacencies{};
    unordered_set<int> visited{};
    unordered_set<int> batched{};
    for (auto &meeting: meetings) {
        if (meeting[2] != t) {
            t=meeting[2];
            for (auto node:batched) {
                if (visited.contains(node))
                    continue;
                visited.insert(node);
                dfs(adjacencies,visited,withSecret,node);
            }
            batched={};
            adjacencies = {};
            visited = {};
        }
        if (!adjacencies.contains(meeting[0])) {
            adjacencies[meeting[0]] = {};
        }
        if (!adjacencies.contains(meeting[1])) {
            adjacencies[meeting[1]] = {};
        }
        adjacencies[meeting[0]].insert(meeting[1]);
        adjacencies[meeting[1]].insert(meeting[0]);
        if (withSecret.contains(meeting[0]) || withSecret.contains(meeting[1])) {
            withSecret.insert(meeting[0]);
            batched.insert(meeting[0]);
            withSecret.insert(meeting[1]);
            batched.insert(meeting[1]);
        }
    }
    for (auto node:batched) {
        if (visited.contains(node))
            continue;
        visited.insert(node);
        dfs(adjacencies,visited,withSecret,node);
    }
    result.insert(result.end(), withSecret.begin(), withSecret.end());
    return result;
}

void LeetCode2092FindAllPeopleWithSecret::Run() {
    int n = 6;
    vector<vector<int> > meetings{{1, 2, 5}, {2, 3, 8}, {1, 5, 10}};
    int firstPerson = 1;
    Auxilaries::PrintVector(findAllPeople(n, meetings, firstPerson));
}
