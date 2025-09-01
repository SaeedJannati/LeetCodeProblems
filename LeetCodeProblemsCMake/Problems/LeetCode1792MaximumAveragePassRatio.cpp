//
// Created by saeed on 9/1/25.
//

#include "LeetCode1792MaximumAveragePassRatio.h"

#include <queue>
using namespace std;
double LeetCode1792MaximumAveragePassRatio::maxAverageRatio( vector< vector<int>> &classes, int extraStudents) {
    priority_queue<pair<double,int> > nextDelta{};
    int length= static_cast<int>(classes.size());
    double delta = 0;
    for (int i = 0; i < length; i++) {
        delta=(classes[i][1]-classes[i][0]);
        delta/=classes[i][1];
        delta/= (classes[i][1]+1);
        nextDelta.emplace(delta,i);
    }
    for (int i=0;i<extraStudents;i++) {
        auto [_,index] = nextDelta.top();
        nextDelta.pop();
        classes[index][0]++;
        classes[index][1]++;
        delta=(classes[index][1]-classes[index][0]);
        delta/=classes[index][1];
        delta/= (classes[index][1]+1);
        nextDelta.emplace(delta,index);
    }
    delta=0;
    for (auto & aClass: classes) {
        delta+= static_cast<double>(aClass[0])/aClass[1];
    }
    return delta/length;
}