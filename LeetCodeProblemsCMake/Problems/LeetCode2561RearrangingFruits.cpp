//
// Created by saeed on 8/2/25.
//

#include "LeetCode2561RearrangingFruits.h"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <ostream>
#include <unordered_map>
#include <bits/ranges_algo.h>
using namespace std;

long long LeetCode2561RearrangingFruits::minCost(vector<int> &basket1, vector<int> &basket2) {
    unordered_map<int,int> firstMap{};
    unordered_map<int,int> secondMap{};
    unordered_map<int,int> sumMap{};
    int minNum=numeric_limits<int>::max();
    for(auto num:basket1) {
        firstMap[num]++;
        sumMap[num]++;
        minNum = min(minNum,num);
    }
    for(auto num:basket2) {
        secondMap[num]++;
        sumMap[num]++;
        minNum = min(minNum,num);
    }
    vector<int> valuesToCheck{};
    int totalChangesNeeded{};
    for (auto & pair:sumMap) {
        if (pair.second %2==1)
            return -1;
        sumMap[pair.first]=abs(firstMap[pair.first]-secondMap[pair.first]);
        if (sumMap[pair.first]>0) {
            sumMap[pair.first]>>=1;
            totalChangesNeeded+=sumMap[pair.first];
            valuesToCheck.push_back(pair.first);
        }
    }
    totalChangesNeeded>>=1;
    int changesMade{};
    ranges::sort(valuesToCheck);
    long long ans{};
    for(auto num:valuesToCheck) {
        long long coefficient=min(totalChangesNeeded-changesMade,sumMap[num]);
        changesMade+=coefficient;
       long long delta=coefficient*num;
        if (num>2*minNum) {
            delta=coefficient*2*minNum;
        }
        ans+=delta;
        if(changesMade==totalChangesNeeded)
            break;
    }
    return ans;
}

void LeetCode2561RearrangingFruits::Run() {
    vector<int> basket1{84,80,43,8,80,88,43,14,100,88};
    // {4,4,4,4,3};
    // {4,2,2,2};
    vector<int> basket2{32,32,42,68,68,100,42,84,14,8};
    // {5,5,5,5,3};
    // {1,4,1,2};
    cout<<minCost(basket1,basket2)<<endl;
}
