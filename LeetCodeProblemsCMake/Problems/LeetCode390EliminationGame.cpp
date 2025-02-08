//
// Created by saeed on 2/8/25.
//

#include "LeetCode390EliminationGame.h"

#include <iostream>
#include <numeric>
#include <ostream>
#include <vector>

#pragma region with recursion
int Eliminate(int &head, int &step, bool &fromLeft, int &n) {
    if (n == 1)
        return head;
    if (fromLeft || (n & 1) == 1) {
        head += step;
    }
    step <<= 1;
    fromLeft = !fromLeft;
    n >>= 1;
    return Eliminate(head, step, fromLeft, n);
}

int LeetCode390EliminationGame::lastRemaining(int n) {
    int step = 1;
    int head = 1;
    bool fromLeft = true;
   return Eliminate(head, step, fromLeft, n);
}
#pragma  endregion
#pragma region without recursion
// int LeetCode390EliminationGame::lastRemaining(int n) {
//     int step = 1;
//     int head = 1;
//     bool fromLeft = true;
//     while (n > 1) {
//         if (fromLeft || n % 2 == 1) {
//             head += step;
//         }
//         step <<= 1;
//         fromLeft = !fromLeft;
//         n >>= 1;
//     }
//     return head;
// }
#pragma endregion

void LeetCode390EliminationGame::Run() {
    int n = 123;
    std::cout << LeetCode390EliminationGame::lastRemaining(n) << std::endl;
}
