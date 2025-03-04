//
// Created by saeed on 3/4/25.
//

#include "LeetCode1780CheckIfNumberIsASumOfPowersOfThree.h"

bool LeetCode1780CheckIfNumberIsASumOfPowersOfThree::checkPowersOfThree(int n) {
    while(n>0) {
        if(n%3==2)
            return false;
        n/=3;
    }
    return true;
}
