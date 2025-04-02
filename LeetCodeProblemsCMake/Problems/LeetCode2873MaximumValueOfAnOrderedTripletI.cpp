//
// Created by saeed on 4/2/25.
//

#include "LeetCode2873MaximumValueOfAnOrderedTripletI.h"
using namespace std;
long long LeetCode2873MaximumValueOfAnOrderedTripletI::maximumTripletValue(vector<int> &nums) {
    int length = static_cast<int>( nums.size());
    long long max{};
    long long current{};
    for (int i = 0; i < length-2; i++) {
        for (int j = i + 1; j < length-1; j++) {
            for (int k = j + 1; k < length; k++) {
                current = nums[i]-nums[j];
                current*=nums[k];
                max=std::max(current,max);
            }
        }
    }
    return  max;
}
