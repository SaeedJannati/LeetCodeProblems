//
// Created by saeed on 2/20/25.
//

#include "LeetCode1980FindUniqueBinaryString.h"

#include <algorithm>
#include <iostream>
#include <unordered_set>

std::string LeetCode1980FindUniqueBinaryString::findDifferentBinaryString(std::vector<std::string> &nums) {
    int n = nums.size();
    std::unordered_set<int> numbers{};
    numbers.reserve(n);
    int num{};
    for (int i = 0; i < n; i++) {
        num=0;
        for (int j=n-1; j>=0; j--) {
            if (nums[i][j]!='1')
                continue;
            num+= 1<<(n-1-j);
        }
        numbers.insert(num);
    }
    std::string result{};
    for (int i=0; i<n+1; i++) {
        if (numbers.contains(i))
            continue;
        for (int j=0; j<n; j++) {
            if (i&(1<<j))
                result += '1';
            else
                result += '0';
        }
        break;
    }
    std::ranges::reverse(result);
    return result;
}

void LeetCode1980FindUniqueBinaryString::Run() {
    std::vector<std::string> nums={"0111","0000","1001","1111"};
        // {"111","011","001"};
        // {"01","10"};
    std::cout<<findDifferentBinaryString(nums)<<std::endl;
}
