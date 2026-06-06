//
// Created by Saeed Jannati on 6/6/26.
//

#include "LeetCode2574LeftAndRightSumDifferences.h"
using namespace std;

vector<int> LeetCode2574LeftAndRightSumDifferences::leftRightDifference(vector<int> &nums) {
    int length= static_cast<int>(nums.size());
    vector<int> left(length,0);
    vector<int> right(length,0);
    for (int i=1;i<length;i++) {
        left[i]=left[i-1]+nums[i-1];
        right[length-i-1]=right[length-i]+nums[length-i];
    }
    for (int i=0;i<length;i++) {
        nums[i]= abs(left[i]-right[i]);
    }
    return nums;
}
