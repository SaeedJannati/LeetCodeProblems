//
// Created by Saeed Jannati on 5/31/26.
//

#include "LeetCode2126DestroyingAsteroids.h"
using namespace std;

bool LeetCode2126DestroyingAsteroids::asteroidsDestroyed(int mass, vector<int> &asteroids) {
    ranges::sort(asteroids);
    long long aggregatedMass=mass;
    for ( auto asteroid:asteroids) {
        if (asteroid>aggregatedMass) {
            return false;
        }
        aggregatedMass+=asteroid;
    }
    return true;
}
