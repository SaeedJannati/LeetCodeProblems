//
// Created by saeed on 2/6/25.
//

#include "LeetCode264UglyNumberII.h"

#include <iostream>
#include <ostream>
#include <queue>
#include <unordered_set>
#include <vector>
#pragma region O(N)
int LeetCode264UglyNumberII::nthUglyNumber(int n) {
    std::pmr::vector<int> uglyNums{};
    uglyNums.reserve(n);
    uglyNums.push_back(1);
    int l1 = 0;
    int l2 = 0;
    int l3 = 0;
    int ugly1 = 0;
    int ugly2 = 0;
    int ugly3 = 0;
    int nextUgly = 0;
    while (uglyNums.size() < n) {
        ugly1 = uglyNums[l1] * 2;
        ugly2 = uglyNums[l2] * 3;
        ugly3 = uglyNums[l3] * 5;
        nextUgly = std::min(ugly1, ugly2);
        nextUgly = std::min(nextUgly, ugly3);
        if (nextUgly == ugly1) {
            l1++;
        }
        if (nextUgly == ugly2) {
            l2++;
        }
        if (nextUgly == ugly3) {
            l3++;
        }
        uglyNums.push_back(nextUgly);
    }
    return uglyNums.back();
}
#pragma endregion
#pragma region O(NLogN) using min heap
// int LeetCode264UglyNumberII::nthUglyNumber(int n) {
//     std::priority_queue<long, std::vector<long>, std::greater<long> > minHeap;
//     std::unordered_set<long> set{};
//     minHeap.push(1);
//     long num = 0;
//     long newUgly=0;
//     for (int i = 0; i < n; i++) {
//         num = minHeap.top();
//         minHeap.pop();
//         newUgly = num * 2;
//         if (!set.contains(newUgly)) {
//             minHeap.push(num * 2);
//             set.insert(newUgly);
//         }
//         newUgly = num * 3;
//         if (!set.contains(newUgly)) {
//             minHeap.push(newUgly);
//             set.insert(newUgly);
//         }
//         newUgly = num * 5;
//         if (!set.contains(newUgly)) {
//             minHeap.push(newUgly);
//             set.insert(newUgly);
//         }
//     }
//     return num;
// }
#pragma  endregion

void LeetCode264UglyNumberII::Run() {
    int n = 10;
    std::cout << nthUglyNumber(n) << std::endl;
}
