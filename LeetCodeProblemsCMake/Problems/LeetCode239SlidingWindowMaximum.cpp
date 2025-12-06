//
// Created by saeed on 12/6/25.
//

#include "LeetCode239SlidingWindowMaximum.h"

#include <deque>
using namespace std;

vector<int> LeetCode239SlidingWindowMaximum::maxSlidingWindow(vector<int> &nums, int k) {
    int length = static_cast<int>(nums.size());
    vector<int> result{};
    result.reserve(length - k + 1);
    deque<int> deque{};
    for (int i = 0; i < k; i++) {
        while (!deque.empty() && nums[deque.back()] <= nums[i]) {
            deque.pop_back();
        }
        deque.push_back(i);
    }
    result.emplace_back(nums[deque.front()]);
    for (int i = k; i < length; i++) {
        if (!deque.empty() && i - k == deque.front()) {
            deque.pop_front();
        }
        while (!deque.empty() && nums[deque.back()] <= nums[i]) {
            deque.pop_back();
        }
        deque.push_back(i);
        result.emplace_back(nums[deque.front()]);
    }
    return result;
}
