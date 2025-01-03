//
// Created by saeed on 1/3/25.
//

#include "LeetCode47PermutationsII.h"

#include <algorithm>

std::vector<std::vector<int> > LeetCode47PermutationsII::permuteUnique(std::vector<int> &nums) {
    const int length = static_cast<int>(nums.size());
    if (length == 1)
        return {{nums[0]}};
    std::ranges::sort(nums);
    std::vector<std::vector<int> > result;

        std::vector<int> permutaion={};
   auto visited=std::vector<bool>(length,false);
        Backtrack(nums,result,permutaion,length,0,visited);

    return result;
}

void LeetCode47PermutationsII::Backtrack(std::vector<int> &nums, std::vector<std::vector<int> > &result,  std::vector<int> &permutation,
               int numsLength, int currentLength,std::vector<bool>& visited) {
    if (currentLength == numsLength) {
        result.push_back(permutation);
        return;
    }
    int lastNum=-11;
    for (int i = 0; i < numsLength; i++) {
        if (visited[i])
            continue;
        if (nums[i] == lastNum) {
            continue;
        }
        visited[i] = true;
        lastNum = nums[i];
        auto newPermutation=permutation;
        newPermutation.push_back(nums[i]);
        Backtrack(nums,result,newPermutation,numsLength,currentLength+1,visited);
        visited[i] = false;
    }
}

void LeetCode47PermutationsII::Run() {
   std::vector<int> nums{1,1,2};
    permuteUnique(nums);
}
