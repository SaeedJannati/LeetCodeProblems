//
// Created by saeed on 4/29/25.
//

#include "LeetCode2962CountSubarraysWhereMaxElementAppearsAtLeastKTimes.h"

#include <iostream>
#include <ostream>
using namespace std;
long long LeetCode2962CountSubarraysWhereMaxElementAppearsAtLeastKTimes::countSubarrays(vector<int> &nums, int k) {
    int  max{};
    int maxOccurrence{};
    for (auto num : nums) {
        if (num > max) {
            max = num;
            maxOccurrence = 1;
        }
        else if (num == max) {
            maxOccurrence++;
        }
    }
    if ( maxOccurrence<k)
        return 0;
    int length=static_cast<int>(nums.size());
    int maxCount{};
    int second{-1};
    long long result{};
    for (int i=0;i<length;i++) {
        while (maxCount<k) {
            second++;
            if (second>=length)
                break;
            if (nums[second]==max) {
                maxCount++;
            }
        }
        if (maxCount==k) {
            result+=std::max(1,length-second);
        }
        if (nums[i]==max) {
            maxCount--;
        }
    }
    return result;
}

void LeetCode2962CountSubarraysWhereMaxElementAppearsAtLeastKTimes::Run() {
    vector<int> nums{1,3,2,3,3};
    int k=2;
    long long result=countSubarrays(nums,k);
    cout<<result<<endl;
}
