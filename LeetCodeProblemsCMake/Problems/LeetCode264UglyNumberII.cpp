//
// Created by saeed on 2/6/25.
//

#include "LeetCode264UglyNumberII.h"

#include <iostream>
#include <ostream>
#include <queue>
#include <unordered_set>
#include <vector>


int LeetCode264UglyNumberII::nthUglyNumber(int n) {
    std::priority_queue<long, std::vector<long>, std::greater<long> > minHeap;
    std::unordered_set<long> set{};
    minHeap.push(1);
    long num = 0;
    long newUgly=0;
    for (int i = 0; i < n; i++) {
        num = minHeap.top();
        minHeap.pop();
        newUgly = num * 2;
        if (!set.contains(newUgly)) {
            minHeap.push(num * 2);
            set.insert(newUgly);
        }
        newUgly = num * 3;
        if (!set.contains(newUgly)) {
            minHeap.push(newUgly);
            set.insert(newUgly);
        }
        newUgly = num * 5;
        if (!set.contains(newUgly)) {
            minHeap.push(newUgly);
            set.insert(newUgly);
        }
    }
    return num;
}

void LeetCode264UglyNumberII::Run() {
    int n=10;
    std::cout <<nthUglyNumber(n) << std::endl;
}
