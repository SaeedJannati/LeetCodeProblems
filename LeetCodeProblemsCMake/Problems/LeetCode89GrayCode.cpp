//
// Created by saeed on 1/23/25.
//

#include "LeetCode89GrayCode.h"

#include <complex>
#include <unordered_map>
#include <unordered_set>

#include "../Auxilary/Auxilaries.h"

std::vector<int> LeetCode89GrayCode::grayCode(int n) {
    const int count = 1 << n;
    std::vector result(count, 0);
    for (int i = 0; i < count; i++) {
        result[i] = i ^ i >> 1;
    }
    return result;
}

void LeetCode89GrayCode::Run() {
    int n = 4;
    auto result = grayCode(n);
    Auxilaries::PrintVector(result);
}
