//
// Created by saeed on 8/29/25.
//

#include "LeetCode3021AliceAndBobPlayingFlowerGame.h"

long long LeetCode3021AliceAndBobPlayingFlowerGame::flowerGame(int n, int m) {
    long long result {0};
    long long firstEven=n/2;
    long long firstOdd=n-n/2;
    long long secondEven=m/2;
    long long secondOdd=m-m/2;
    result= firstEven*secondOdd+firstOdd*secondEven;
    return result;
}
