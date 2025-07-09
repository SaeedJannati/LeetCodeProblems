//
// Created by saeed on 4/28/25.
//

#include "LeetCode2302CountSubarraysWithScoreLessThanK.h"

#include <iostream>
#include <ostream>
using namespace std;

int findIndex(vector<long long> &prefixSum, int num,int index, long long k, int length) {
    int begin = index;
    int end = length-1 ;
    int mid{};
    int result{-1};
    long long mult{};
    while (begin <= end) {
        mid = (begin + end) / 2;
        mult = (prefixSum[mid] - prefixSum[index]+num) * static_cast<long long>(mid - index+1);
        if (mult < k) {
            result = std::max(result, mid);
            begin = mid + 1;
            continue;
        }
        end = mid - 1;
    }
    return result;
}

long long LeetCode2302CountSubarraysWithScoreLessThanK::countSubarrays(vector<int> &nums, long long k) {
    int length = static_cast<int>(nums.size());
    long long result{};
    vector<long long> prefixSum(length , 0);
    prefixSum[0] = nums[0];
    int index{};
    for (int i = 1; i < length; i++) {
        prefixSum[i] = prefixSum[i-1] + nums[i];
    }
    for (int i = 0; i < length; i++) {
        index = findIndex(prefixSum,nums[i], i, k, length);
        if (index == -1)
            continue;
        result += index-i+1;
    }
    return result;
}

void LeetCode2302CountSubarraysWithScoreLessThanK::Run() {
    vector<int> nums
    {2,1,4,3,5};
    // {1,1,1};
    int k=
        10;
        // 5;
    long long result = countSubarrays(nums, k);
    cout << result << endl;
}
