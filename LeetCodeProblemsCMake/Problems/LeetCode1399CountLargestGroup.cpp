//
// Created by saeed on 4/23/25.
//

#include "LeetCode1399CountLargestGroup.h"

#include <unordered_map>
using namespace std;
int countDigitSum(int num) {
    int sum{};
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
int LeetCode1399CountLargestGroup:: countLargestGroup(int n){
    unordered_map<int, int> map{};
    int maxNum{};
    int digitSum{};
    for (int i=1; i<=n; i++) {
        digitSum = countDigitSum(i);
        if (!map.contains(digitSum)) {
            map[digitSum] = 0;
        }
        map[digitSum]++;
        maxNum = max(maxNum, map[digitSum]);
    }
    int result{};
    for (auto & pair : map) {
        if (pair.second != maxNum)
            continue;
        result++;
    }
    return  result;
}
