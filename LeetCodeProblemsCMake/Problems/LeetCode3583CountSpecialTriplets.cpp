//
// Created by saeed on 12/9/25.
//

#include "LeetCode3583CountSpecialTriplets.h"

#include <iostream>
#include <ostream>
#include <unordered_map>

using namespace std;

int LeetCode3583CountSpecialTriplets::specialTriplets(vector<int> &nums) {
    unordered_map<int, vector<pair<int,int>> > numsMap{};
    int mod=1e9+7;
    int length = static_cast<int>(nums.size());
    for (int i = 0; i < length; ++i) {
        if (!numsMap.contains(nums[i])) {
            numsMap[nums[i]] = {};
        }
        numsMap[nums[i]].emplace_back(i,numsMap[nums[i]].size());
    }
    long count = 0;
    long delta{};
    int doubleValue{};
    for (int i = 1; i < length - 1; ++i) {
        doubleValue = nums[i] << 1;
        if (!numsMap.contains(doubleValue))
            continue;
        if (numsMap[doubleValue][0].first>i)
            continue;
        int begin=numsMap[doubleValue][0].second;
        int doubleSize=static_cast<int>(numsMap[doubleValue].size());
        if (numsMap[doubleValue][doubleSize-1].first<i)
            continue;
        int end=numsMap[doubleValue][doubleSize-1].second;
        int mid{};
        int lastSmaller{-1};
        while (begin<=end) {
            mid= (begin+end)>>1;
            if (numsMap[doubleValue][mid].first<i) {
                lastSmaller=max(lastSmaller,numsMap[doubleValue][mid].second);
                begin=mid+1;
                continue;
            }
            end=mid-1;
        }
        delta=lastSmaller+1;
        long afterOffset= numsMap[doubleValue][lastSmaller+1].first==i?doubleSize-lastSmaller-2:doubleSize-lastSmaller-1;
        delta*= afterOffset;
        delta%=mod;
        count+=delta;
        count%=mod;
    }
    return count;
}

void LeetCode3583CountSpecialTriplets::Run() {
    vector<int> nums={6,3,6};
    cout<<specialTriplets(nums)<<endl;
}
