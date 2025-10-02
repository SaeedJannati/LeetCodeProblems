//
// Created by saeed on 10/2/25.
//

#include "LeetCode3100WaterBottlesII.h"

#include <cmath>
using namespace std;
int LeetCode3100WaterBottlesII::maxBottlesDrunk(int numBottles, int numExchange) {
    int drankBottles{};
    int emptyBottles{};
    int temp{};
    int newBottles{};
    int delta{};
    while (numBottles+emptyBottles>=numExchange) {
        temp=numBottles;
        emptyBottles+=numBottles;
        newBottles = (-2*numExchange - 1 + sqrt(4*numExchange*numExchange - 4*numExchange + 8*emptyBottles + 1))/2;
        delta = (newBottles + 1)*numExchange + newBottles*(newBottles+1)/2;
        numExchange+=newBottles+1;
        emptyBottles-=delta;
        numBottles=newBottles+1;
        drankBottles+=temp;
    }
    drankBottles+=numBottles;
    return drankBottles;
}
