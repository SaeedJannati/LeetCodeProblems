//
// Created by saeed on 11/9/25.
//

#include "LeetCode2169CountOperationsToObtainZero.h"

int LeetCode2169CountOperationsToObtainZero::countOperations(int num1, int num2) {
    int counter{};
    while (num1 != 0 && num2 != 0) {
        if (num1 >= num2) {
            num1 -= num2;
        } else {
            num2 -= num1;
        }
        ++counter;
    }
    return counter;
}
