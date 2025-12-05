//
// Created by saeed on 12/5/25.
//

#include "LeetCode3432CountPartitionsWithEvenSumDifference.h"

#include <iostream>
#include <ostream>
using namespace std;
int LeetCode3432CountPartitionsWithEvenSumDifference::countPartitions( vector<int> &nums) {
    int length= static_cast<int>(nums.size());
    vector<int> prefixSums(length+1);
    for(int i=0; i<length; i++) {
        prefixSums[i+1] = prefixSums[i] + nums[i];
    }
    int result{};
    int sumAfter{};
    int sumBefore{};
    for (int i=0; i<length-1; i++) {
        sumAfter= prefixSums[length]-prefixSums[i+1];
        sumBefore=prefixSums[length]-sumAfter;
        if ((sumAfter-sumBefore)%2==0) {
            ++result;
        }
    }
    return result;
}

void LeetCode3432CountPartitionsWithEvenSumDifference::Run() {
    vector<int> nums{10,10,3,7,6};
    cout<<countPartitions(nums)<<endl;
}
