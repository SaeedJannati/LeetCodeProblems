//
// Created by saeed on 6/12/25.
//

#include "LeetCode3423MaximumDifferenceBetweenAdjacentElementsInACircularArray.h"

#include <cmath>
using namespace std;
int LeetCode3423MaximumDifferenceBetweenAdjacentElementsInACircularArray::maxAdjacentDistance(std::vector<int> &nums) {
    int length=static_cast<int>( nums.size());
    int maxDiff= abs(nums[0]-nums[length-1]);
    int diff{};
    for(int i=1;i<length;i++) {
         diff = abs(nums[i]-nums[i-1]);
        if(diff>maxDiff) {
            maxDiff = diff;
        }
    }
    return maxDiff;
}
