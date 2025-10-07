//
// Created by saeed on 10/7/25.
//

#include "LeetCode1488AvoidFloodInTheCity.h"

#include <queue>
#include <unordered_set>

#include "../Auxilary/Auxilaries.h"
using namespace std;

vector<int> LeetCode1488AvoidFloodInTheCity::avoidFlood(vector<int> &rains) {
    unordered_set<int> filledLakes{};
    vector<int> floodOrder{};
    int zeroCount{};
    for (auto rain: rains) {
        if (rain == 0) {
            ++zeroCount;
            continue;
        }
        if (filledLakes.contains(rain)) {
            floodOrder.emplace_back(rain);
            if (floodOrder.size() > zeroCount)
                return {};
            continue;
        }
        filledLakes.insert(rain);
    }
    if (floodOrder.size() > zeroCount) {
        return {};
    }
    vector<int> result(rains.size(), -1);
    filledLakes = {};
    for (int i = 0, e = rains.size(); i < e; ++i) {
        if (rains[i] != 0) {
            if (filledLakes.contains(rains[i]))
                return {};
            filledLakes.insert(rains[i]);
            continue;
        }
        if (floodOrder.empty()) {
            result[i] = 1;
            continue;
        }
        if (filledLakes.empty()) {
            result[i] = 1;
            continue;
        }
        int res=floodOrder.size();
        for (int i=0;i<floodOrder.size();++i){
            if (filledLakes.contains(floodOrder[i])){
                res=i;
                break;
            }
        }
        if (res == floodOrder.size() ) {
            result[i] = 1;
            continue;
        }
        result[i] = floodOrder[res];
        filledLakes.erase(floodOrder[res]);
        floodOrder.erase(floodOrder.begin() + res);
    }
    return result;
}

void LeetCode1488AvoidFloodInTheCity::Run() {
    vector<int> rains = {0,0,0,28663,0,0,0,0,0,0,0,0,95827,0,0,85637,0,0,0,45506,95827,85637,0,0,45506,0,0,0,28663,0,0,0,0,60812,0,0,0,0,60812,0,0,0,0,0,0,0,0};
    Auxilaries::PrintVector(avoidFlood(rains));
}
