//
// Created by saeed on 12/4/25.
//

#include "LeetCode2211CountCollisionsOnARoad.h"

#include <iostream>
#include <stack>
using namespace std;

int LeetCode2211CountCollisionsOnARoad::countCollisions(string directions) {
    stack<char> directionStack{};
    int collisionCount{};
    for (auto direction: directions) {
        if (direction == 'R') {
            directionStack.push(direction);
            continue;
        }
        if (directionStack.empty()) {
            directionStack.push(direction);
            continue;
        }
        if (directionStack.top() == direction) {
            directionStack.push(direction);
            continue;
        }
        if (direction == 'S') {
            if (directionStack.top() == 'R') {
                while (!directionStack.empty() && directionStack.top() == 'R') {
                    directionStack.pop();
                    ++collisionCount;
                }
            }
            directionStack.push('S');
        }
        if (direction == 'L') {
            if (directionStack.top() == 'R') {
                directionStack.pop();
                collisionCount += 2;
                while (!directionStack.empty() && directionStack.top() == 'R') {
                    directionStack.pop();
                    ++collisionCount;
                }
                directionStack.push('S');
                continue;
            }
            ++collisionCount;
        }
    }
    return collisionCount;
}

void LeetCode2211CountCollisionsOnARoad::Run() {
    string directions="RSLLRSSL";
    cout<<countCollisions(directions)<<'\n';
}
