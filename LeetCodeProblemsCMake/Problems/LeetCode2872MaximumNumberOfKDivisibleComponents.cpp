//
// Created by saeed on 11/28/25.
//

#include "LeetCode2872MaximumNumberOfKDivisibleComponents.h"

#include <unordered_map>
using namespace std;

int Dfs(vector<int> &values, int k, vector<bool> &visited, unordered_map<int,vector<int>> &adjPlus, int &result,
        int index) {
    int branchMod{};
    int mod= values[index]%k;
    for (auto neighbour: adjPlus[index]) {
        if (!visited[neighbour]) {
            visited[neighbour] = true;
            branchMod = Dfs(values, k, visited, adjPlus, result, neighbour);
            if (branchMod == 0) {
                ++result;
            }
            else {
                mod+= branchMod%k;
                mod%= k;
            }
        }
    }
    return mod;
}

int LeetCode2872MaximumNumberOfKDivisibleComponents::maxKDivisibleComponents(int n,
                                                                             vector<vector<int> > &edges,
                                                                             vector<int> &values, int k) {
    vector<bool> visited(n, false);
    unordered_map<int, vector<int> > adjPlus{};
    for (auto &edge: edges) {
        if (!adjPlus.contains(edge[0])) {
            adjPlus[edge[0]] = {};
        }
        adjPlus[edge[0]].push_back(edge[1]);
        if (!adjPlus.contains(edge[1])) {
            adjPlus[edge[1]] = {};
        }
        adjPlus[edge[1]].push_back(edge[0]);
    }
    int result{1};
    visited[0] = true;
    Dfs(values,k,visited,adjPlus,result,0);
    return result;
}
