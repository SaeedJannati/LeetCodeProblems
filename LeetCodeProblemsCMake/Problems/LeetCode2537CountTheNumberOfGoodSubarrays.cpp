//
// Created by saeed on 4/17/25.
//

#include "LeetCode2537CountTheNumberOfGoodSubarrays.h"

#include <iostream>
#include <ostream>
#include <unordered_map>
using namespace std;

long getPermutationsCount(int count, unordered_map<int, long long> &memo) {
    if (count == 0 || count == 1) {
        return 0;
    }
    if (memo.contains(count))
        return memo[count];
    memo[count] = count * (count - 1) / 2;
    return memo[count];
}

long long LeetCode2537CountTheNumberOfGoodSubarrays::countGood(vector<int> &nums, int k) {
    int length = static_cast<int>(nums.size());
    if (length == 1)
        return 0;
    long long result = 0;
    long long totalCount = length % 2 == 0 ? length / 2 : (length + 1) / 2;
    totalCount *= length % 2 == 0 ? length + 1 : length;
    unordered_map<int, long long> memo{};
    unordered_map<int, int> numsCount{};
    long long pairCount{};
    int firstPointer{};
    int secondPointer{};
    numsCount[nums[0]] = 1;
    while (firstPointer < length) {
        while (pairCount < k && secondPointer < length) {
            secondPointer++;
            if (secondPointer == length) {
                break;
            }
            if (!numsCount.contains(nums[secondPointer])) {
                numsCount[nums[secondPointer]] = 0;
            }
            pairCount -= getPermutationsCount(numsCount[nums[secondPointer]], memo);
            numsCount[nums[secondPointer]]++;
            pairCount += getPermutationsCount(numsCount[nums[secondPointer]], memo);
        }
        secondPointer = min(secondPointer, length - 1);
        result += secondPointer - firstPointer+(pairCount>=k?0:1);
        pairCount -= getPermutationsCount(numsCount[nums[firstPointer]], memo);
        numsCount[nums[firstPointer]]--;
        pairCount += getPermutationsCount(numsCount[nums[firstPointer]], memo);
        firstPointer++;
        while (pairCount >= k && firstPointer <= secondPointer) {
            pairCount -= getPermutationsCount(numsCount[nums[secondPointer]], memo);
            numsCount[nums[secondPointer]]--;
            pairCount += getPermutationsCount(numsCount[nums[secondPointer]], memo);
            secondPointer--;
        }
    }
    return totalCount - result;
}

void LeetCode2537CountTheNumberOfGoodSubarrays::Run() {
    vector<int> nums =
            // {1, 1, 1, 1, 1};
    {3,1,4,3,2,2,4};
    int k =
            // 10;
    2;
    cout << countGood(nums, k) << endl;
}
