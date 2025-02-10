//
// Created by saeed on 2/10/25.
//

#include "LeetCode3174ClearDigits.h"

#include <stack>

std::string LeetCode3174ClearDigits::clearDigits(std::string s) {
    std::stack<char> chars{};
    int remainingDigitCount = 0;
    int length = s.length();
    for (int i=length-1;i>=0;i--) {
        if (s[i]>='0' && s[i]<='9') {
            remainingDigitCount++;
            continue;
        }
        if (remainingDigitCount>0) {
            remainingDigitCount--;
        continue;
        }
        chars.push(s[i]);
    }
    std::string result{};
    while (chars.size()>0) {
        result += chars.top();
        chars.pop();
    }
    return result;
}
