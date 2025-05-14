//
// Created by saeed on 5/14/25.
//

#include "LeetCode260SingleNumberIII.h"

#include "../Auxilary/Auxilaries.h"

std::vector<int> LeetCode260SingleNumberIII::singleNumber(std::vector<int> &nums) {
    int length=static_cast<int>(nums.size());
    if (length==2)
        return nums;
    int xorResult{};
    for (int i=0; i<length; i++) {
        xorResult ^= nums[i];
    }
    int firstRightBit=1;
    while (true) {
        if ((firstRightBit&xorResult)==firstRightBit) {
            break;
        }
        firstRightBit <<= 1;
    }
    int firstNum{};
    for (int i=0; i<length; i++) {
        if ((nums[i]&firstRightBit)==0)
            continue;
        firstNum ^= nums[i];
    }
    int secondNum=xorResult^firstNum;
    return {firstNum,secondNum};
}

void LeetCode260SingleNumberIII::Run() {
    std::vector<int> nums{1,2,1,3,2,5};
    Auxilaries::PrintVector(singleNumber(nums));
}
