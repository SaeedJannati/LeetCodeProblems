//
// Created by saeed on 9/4/25.
//

#include "LeetCode3516FindClosestPerson.h"

#include <cmath>
#include <math.h>

int LeetCode3516FindClosestPerson::findClosest(int x, int y, int z) {
    int delta=  abs(x - z) - abs(y - z);
    if(delta>0)
        return 2;
    if (delta<0)
        return 1;
    return 0;
}
