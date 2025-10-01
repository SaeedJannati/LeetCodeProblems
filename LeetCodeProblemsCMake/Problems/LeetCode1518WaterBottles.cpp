//
// Created by saeed on 10/1/25.
//

#include "LeetCode1518WaterBottles.h"

int LeetCode1518WaterBottles::numWaterBottles(int numBottles, int numExchange) {
    int drankBottleCount{};
    int tempNumBottles{};
    int emptyBottles{};
    while (numBottles + emptyBottles >= numExchange) {
        tempNumBottles = numBottles;
        emptyBottles += numBottles;
        numBottles = emptyBottles / numExchange;
        emptyBottles %= numExchange;
        drankBottleCount += tempNumBottles;
    }
    return drankBottleCount+numBottles;
}
