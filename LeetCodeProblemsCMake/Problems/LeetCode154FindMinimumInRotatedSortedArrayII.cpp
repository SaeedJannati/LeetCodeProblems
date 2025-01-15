//
// Created by saeed on 1/15/25.
//

#include "LeetCode154FindMinimumInRotatedSortedArrayII.h"

#include <iostream>


int GetNext(int index, int maxIndex) {
    auto next = index + 1;
    if (next > maxIndex)
        next = 0;
    return next;
}

int GetPrev(int index, int maxIndex) {
    auto prev = index - 1;
    if (prev < 0)
        prev = maxIndex;
    return prev;
}

int FindRotateIndex(std::vector<int> &nums, int maxIndex) {
    int begin = 0;
    int end = maxIndex;
    if (nums[begin] < nums[end])
        return begin;
    if (begin == end)
        return begin;
    int mid{};
    int next{0};
    int prev{0};
    while (begin <= end) {
        mid = (begin + end) / 2;
        next = GetNext(mid, maxIndex);
        while (next != mid) {
            if (nums[next] == nums[mid]) {
                next = GetNext(next, maxIndex);
            } else
                break;
        }
        prev = GetPrev(mid, maxIndex);
        while (prev != mid) {
            if (nums[mid] == nums[prev])
                prev = GetPrev(prev, maxIndex);
            else break;
        }
        if (next == prev) {
            if (nums[mid] < nums[next])
                return mid;
            return next;
        }
        if (nums[mid] <= nums[prev] && nums[mid] <= nums[next]) {
            return mid;
        }
        if (nums[mid]> nums[next]&&nums[mid]> nums[prev]) {
            return next;
        }
        if (nums[mid] > nums[end]) {
            begin = mid + 1;
            continue;
        }
        end = mid - 1;
    }
    return mid;
}

int LeetCode154FindMinimumInRotatedSortedArrayII::findMin(std::vector<int> &nums) {
    int length = static_cast<int>(nums.size());
    auto index = FindRotateIndex(nums, length - 1);
    return nums[index];
}

void LeetCode154FindMinimumInRotatedSortedArrayII::Run() {
    std::vector<int> nums{
        3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
        3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 2, 3
    };
    std::cout << findMin(nums);
}
