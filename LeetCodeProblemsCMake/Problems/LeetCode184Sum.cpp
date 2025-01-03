//
// Created by saeed on 1/3/25.
//

#include "LeetCode184Sum.h"

#include <algorithm>
#include <limits>

#include "../Auxilary/Auxilaries.h"

std::vector<std::vector<int> > LeetCode184Sum::fourSum(std::vector<int> &nums, int target) {
    std::ranges::sort(nums);
    int length = static_cast<int>(nums.size());
    int firstPointer = 0;
    int secondPointer = 0;
    std::vector<std::vector<int> > result;
    int sum = 0;
    auto * root = new IntTrieNode();
    std::vector<int> temp;
    temp.reserve(4);
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            firstPointer = j + 1;
            secondPointer = length - 1;
            while (firstPointer < secondPointer) {
                sum = nums[i];
                sum+= nums[j];
                sum+= nums[firstPointer];
                sum+= nums[secondPointer];
                if (sum == target) {
                    temp={nums[i], nums[j], nums[firstPointer], nums[secondPointer]};
                    if (root->Add(temp))
                        result.push_back({nums[i], nums[j], nums[firstPointer], nums[secondPointer]});
                    firstPointer++;
                    secondPointer--;
                    continue;
                }
                if (sum > target)
                    secondPointer--;
                else
                    firstPointer++;
            }
        }
    }
    return
            result;
}

void LeetCode184Sum::Run() {
    std::vector<int> nums = {-3, -2, -1, 0, 0, 1, 2, 3};
    int target = 0;
    auto result = fourSum(nums, target);
}


