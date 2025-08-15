//
// Created by saeed on 8/15/25.
//

#include "LeetCode342PowerOfFour.h"

bool LeetCode342PowerOfFour::isPowerOfFour(int n) {
    if ( n<=0)
        return  false;
    if ( (n&(n-1))!=0)
        return  false;
    // chagho laghar 4^x-1  => (4-1) (4^x-1+ 4^x-2+.....+1) => 3*(....)
    if ((n-1)%3==0)
        return  true;
    return false;
}
