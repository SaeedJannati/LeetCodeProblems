//
// Created by saeed on 4/27/25.
//

#include "LeetCode3392CountSubarraysOfLengthThreeWithACondition.h"

#include <iostream>
#include <ostream>
using  namespace std;
int LeetCode3392CountSubarraysOfLengthThreeWithACondition::countSubarrays(vector<int> &nums) {
    int length=static_cast<int>(nums.size());
    if(length<3)
        return 0;
    int result{};
    int sum{};
    for(int i=1;i<length-1;i++) {
        if (nums[i]%2!=0)
            continue;
        sum=nums[i-1]+nums[i+1];
        if (sum!=nums[i]/2)
            continue;
        result++;
    }
    return result;
}

void LeetCode3392CountSubarraysOfLengthThreeWithACondition::Run() {
    vector<int> nums{-1,-4,-1,4};
    cout << countSubarrays(nums) << endl;
}
