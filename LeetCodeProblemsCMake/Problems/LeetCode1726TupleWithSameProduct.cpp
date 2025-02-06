//
// Created by saeed on 2/6/25.
//

#include "LeetCode1726TupleWithSameProduct.h"

#include <unordered_map>

int LeetCode1726TupleWithSameProduct::tupleSameProduct(std::vector<int> &nums) {
    std::unordered_map<int, int> multiplyResults{};
    int length=static_cast<int>( nums.size());
    int result=0;
    for (int i = 0; i < length-1; i++) {
        for (int j=i+1;j<length;j++) {
            result=nums[i]*nums[j];
            if (!multiplyResults.contains(result)) {
                multiplyResults[result]=0;
            }
            multiplyResults[result]++;
        }
    }
    result=0;
    for (auto& pair : multiplyResults) {
        if (pair.second<2)
            continue;
        result+= 8*(pair.second*(pair.second-1))/2;
    }
    return result;
}
