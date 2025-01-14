//
// Created by saeed on 1/14/25.
//

#include "LeetCode2657FindThePrefixCommonArrayOfTwoArrays.h"

#include "../Auxilary/Auxilaries.h"

std::vector<int> LeetCode2657FindThePrefixCommonArrayOfTwoArrays::findThePrefixCommonArray(std::vector<int> &A,
                                                                                           std::vector<int> &B) {
    int size= static_cast<int>(A.size());
    std::vector contains(size, (std::vector(3, false)));
    std::vector result(size,0);
    int prefixCount = 0;
    for(int i = 0; i < size; i++) {
        if (!contains[A[i]-1][0]) {
            contains[A[i]-1][0] = true;
            if (contains[A[i]-1][1]) {
                prefixCount++;
            }
        }
        if (!contains[B[i]-1][1]) {
            contains[B[i]-1][1] = true;
            if (contains[B[i]-1][0]) {
                prefixCount++;
            }
        }
        result[i] = prefixCount;
    }
    return result;
}

void LeetCode2657FindThePrefixCommonArrayOfTwoArrays::Run() {
    std::vector<int> A{1,3,2,4};
    std::vector<int> B{3,1,2,4};
    auto result=findThePrefixCommonArray(A,B);
    Auxilaries::PrintVector(result);
}
