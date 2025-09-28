//
// Created by saeed on 9/28/25.
//

#include "LeetCode976LargestPerimeterTriangle.h"

#include <algorithm>
using  namespace std;
int LeetCode976LargestPerimeterTriangle::largestPerimeter( vector<int> &nums) {
    ranges::sort(nums);
    int length =  static_cast<int>(nums.size());
    int currentPerimeter{nums[length-1]+nums[length-2]+nums[length-3]};
    int maxPerimeter=nums[length-1]>=nums[length-2]+nums[length-3]?0:currentPerimeter;
    for (int i=length-4;i>=0;i--) {
            currentPerimeter-=nums[i+3];
            currentPerimeter+=nums[i];
        if (nums[i+2]>=nums[i+1]+nums[i])
            continue;
            maxPerimeter = max(maxPerimeter,currentPerimeter);
    }
    return maxPerimeter;
}
