//
// Created by saeed on 1/6/25.
//

#include "LeetCode881BoatsToSavePeople.h"

#include <algorithm>
#include <iostream>
#include <ostream>

int LeetCode881BoatsToSavePeople::numRescueBoats(std::vector<int> &people, int limit) {
    std::ranges::sort(people);
    int length = static_cast<int>(people.size());
    int firstPointer = 0;
    int secondPointer = length - 1;
    int counter = 0;
    int aggregateWeight = 0;
    while (firstPointer <= secondPointer) {
        aggregateWeight = people[firstPointer] + people[secondPointer];
        if (aggregateWeight > limit) {
            counter++;
            secondPointer--;
            continue;
        }
        counter++;
        firstPointer++;
        secondPointer--;
    }
    return counter;
}

void LeetCode881BoatsToSavePeople::Run() {
    std::vector<int> people = {3, 5, 3, 4};
    int limit = 5;
    std::cout << numRescueBoats(people, 5) << std::endl;
}
