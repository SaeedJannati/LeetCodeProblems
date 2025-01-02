//
// Created by saeed on 1/2/25.
//

#include "LeetCode2138DivideAStringIntoGroupsOfSizeK.h"

#include "../Auxilary/Auxilaries.h"

std::vector<std::string> LeetCode2138DivideAStringIntoGroupsOfSizeK::divideString(std::string s, int k, char fill) {
    int length = s.length();
    std::vector<std::string> result;
    result.reserve(length / k + 1);
    int counter = 0;
    for (int i = 0, e = length / k; i < e; i++) {
        result.push_back(s.substr(i * k, k));
        counter+=k;
    }
    if (length % k == 0)
        return result;
    std::string str = s.substr(counter, length % k);
    for (int i = 0, e = k - length % k; i < e; i++)
        str.push_back(fill);
    result.push_back(str);
    return result;
}

void LeetCode2138DivideAStringIntoGroupsOfSizeK::Run() {
    std::string s = "abcdefghij";
    int k = 3;
    char fill = 'x';
    auto result = divideString(s, k, fill);
    Auxilaries::PrintVector<std::string>(result);
}
