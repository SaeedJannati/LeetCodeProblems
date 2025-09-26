//
// Created by saeed on 9/26/25.
//

#include "LeetCode611ValidTriangleNumber.h"

#include <algorithm>
using namespace std;

int LeetCode611ValidTriangleNumber::triangleNumber(vector<int> &nums) {
    int length = static_cast<int> (nums.size());
    int result{};
    int sumOfFirstTwo{};
    int begin{};
    int mid{};
    int end{};
    int foundIndex{};
    ranges::sort(nums);
    for (int i = 0; i < length-2; i++) {
        if (nums[i]==0)
            continue;
        for (int j = i+1; j < length-1; j++) {
            sumOfFirstTwo=nums[i]+nums[j];
            foundIndex=i;
            begin=j+1;
            end=length-1;
            while (begin<=end) {
                mid=(begin+end)>>1;
                if (sumOfFirstTwo>nums[mid]) {
                    foundIndex=max(mid,foundIndex);
                    begin=mid+1;
                    continue;
                }
                end=mid-1;
            }
            if (foundIndex>i) {
                result+=foundIndex-j;
            }
        }
    }

    return result;
}
