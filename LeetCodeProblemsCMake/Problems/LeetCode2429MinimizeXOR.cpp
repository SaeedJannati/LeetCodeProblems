//
// Created by saeed on 1/15/25.
//

#include "LeetCode2429MinimizeXOR.h"

#include <bitset>
#include <cmath>
#include <iostream>
#include <math.h>

int LeetCode2429MinimizeXOR::minimizeXor(int num1, int num2) {
    int secondLength =std::max(static_cast<int>( std::ceil(log2(num2+1))),1) ;
    int firstLength= std::max( static_cast<int>( std::ceil(log2(num1+1))),1);
    std::bitset<32> bitsFirst(num1);
    std::bitset<32> result(num2);
    int setBits = 0;
    for (int i = 0; i < secondLength; i++) {
        if (result[i]) {
            setBits++;
        }
    }
    result = std::bitset<32>(false);
    for (int i = firstLength - 1; i >= 0; i--) {
        if (!bitsFirst[i]) {
            result[i] = false;
            continue;
        }
        if (setBits == 0)
            continue;
        setBits--;
        result[i] = true;
    }
    int counter = 0;
    while (setBits > 0) {
        while (result[counter]) {
            counter++;
        }
        result[counter] = true;
        setBits--;
    }
    int outPut = static_cast<int>(result.to_ulong());
    return outPut;
}

void LeetCode2429MinimizeXOR::Run() {
    int num1 = 73;
    int num2 = 32;
    std::cout << minimizeXor(num1, num2) << std::endl;
}
