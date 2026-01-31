//
// Created by saeed on 6/29/25.
//

#include "LeetCode1498NumberOfSubsequencesThatSatisfyTheGivenSumCondition.h"

#include <algorithm>
#include <iostream>
#include <ostream>
using namespace std;
int PowModulo(int base,int power, int modulo) {
    if (power == 0)
        return  1;
    if (power == 1)
        return base;
    int currentPower{1};
    long powOfTwo{base};
    int result{1};
    while (currentPower <= power) {
        if ((power&currentPower)!=0) {
            result=((result%modulo)*( powOfTwo%modulo))%modulo;
        }
        currentPower<<=1;
        powOfTwo= (powOfTwo%modulo*powOfTwo%modulo)%modulo;
        powOfTwo%=modulo;
    }
    return result;
}
int LeetCode1498NumberOfSubsequencesThatSatisfyTheGivenSumCondition::numSubseq(vector<int> &nums, int target) {
    ranges::sort(nums);
    const int modulo = 1e9 + 7;
    long sum{0};
    int foundIndex{0};
    int length = nums.size();
    int begin{0};
    int end{0};
    int mid{0};
    for (int i = 0; i < length ; i++) {
        begin = i;
        end = length - 1;
        foundIndex = -1;
        while (begin <= end) {
            mid = (begin + end) / 2;
            if (nums[i] + nums[mid] <= target) {
                if (mid > foundIndex) {
                    foundIndex = mid;
                }
                begin = mid + 1;
                continue;
            }
            end = mid - 1;
        }
        if (foundIndex == -1)
            continue;
        int subLength=foundIndex-i+1;
        sum += (PowModulo(2,subLength-1,modulo)%modulo);
        sum %= modulo;
    }
    return sum;
}

void LeetCode1498NumberOfSubsequencesThatSatisfyTheGivenSumCondition::Run() {
    vector<int> nums={3,5,6,7};
    int target = 9;
    cout << numSubseq(nums,target) << endl;
}
