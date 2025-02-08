//
// Created by saeed on 2/8/25.
//

#include "LeetCode390EliminationGame.h"

#include <iostream>
#include <numeric>
#include <ostream>
#include <vector>


int LeetCode390EliminationGame::lastRemaining(int n) {
    int step = 1;
    int head = 1;
    bool fromLeft = true;
    while (n > 1) {
        if (fromLeft || n % 2 == 1) {
            head += step;
        }
        step <<= 1;
        fromLeft = !fromLeft;
        n >>= 1;
    }
    return head;
}

void LeetCode390EliminationGame::Run() {
    int n = 123;
    std::cout << LeetCode390EliminationGame::lastRemaining(n) << std::endl;
}
