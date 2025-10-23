//
// Created by saeed on 10/23/25.
//

#include "LeetCode3347MaximumFrequencyOfAnElementAfterPerformingOperationsII.h"

#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

int LeetCode3347MaximumFrequencyOfAnElementAfterPerformingOperationsII::maxFrequency(vector<int> &nums, int k,
    int numOperations) {
    ranges::sort(nums);
    unordered_map<int,int> frequencies{};
    frequencies[nums[0]] = 1;
    int uniquePointer{1};
    for (int i=1,e=static_cast<int>(nums.size());i<e;i++) {
        if (!frequencies.contains(nums[i])) {
            frequencies[nums[i]] = 1;
            swap(nums[i], nums[uniquePointer]);
            uniquePointer++;
            continue;
        }
        frequencies[nums[i]]++;
    }
    vector<long long> prefixSum(uniquePointer , 0);
    for (int i=0;i<uniquePointer;i++) {
        prefixSum[i]=i==0?0:prefixSum[i-1]+frequencies[nums[i-1]];
    }
    int maxFrequency{0};
    int begin{};
    int end{};
    int mid{};
    int left{};
    int right{};
    int currentFrequency{0};
    for (int i=0;i<uniquePointer;i++) {
        begin=0;
        end=i-1;
        left=i;
        while (begin<=end) {
            mid=(begin+end)>>1;
            if ( nums[i]-nums[mid]<=k) {
                end=mid-1;
                left=min(left,mid);
                continue;
            }
            begin=mid+1;
        }
        begin=i+1;
        end=uniquePointer-1;
        right=i;
        while (begin<=end) {
            mid=(begin+end)>>1;
            if ( nums[mid]-nums[i]<=k) {
                begin=mid+1;
                right=max(right,mid);
                continue;
            }
            end=mid-1;
        }
        currentFrequency=frequencies[nums[i]]+min(static_cast<long long>(numOperations),prefixSum[right]-prefixSum[left]+frequencies[nums[right]]-frequencies[nums[i]]);
        maxFrequency=max(maxFrequency,currentFrequency);
    }
    long long lower{};
    long long upper{};
    for (int i=0;i<uniquePointer-1;i++) {
        lower=nums[i];
        lower+=k;
        begin=i;
        right=i;
        end=uniquePointer-1;
        while (begin<=end) {
            mid=(begin+end)>>1;
            upper=nums[mid]-k;
            if (upper<=lower) {
                right=max(right,mid);
                begin=mid+1;
                continue;
            }
            end=mid-1;
        }
        currentFrequency=min(static_cast<long long>(numOperations),prefixSum[right]-prefixSum[i]+frequencies[nums[right]]);
        maxFrequency=max(maxFrequency,currentFrequency);
    }
    return maxFrequency;
}

void LeetCode3347MaximumFrequencyOfAnElementAfterPerformingOperationsII::Run() {
    vector<int> nums{1,2,4,5};
    int k = 2;
    int numOperations = 4;
    cout<< maxFrequency(nums, k, numOperations)<<'\n';
}
