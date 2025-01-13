//
// Created by saeed on 1/13/25.
//

#include "LeetCode204CountPrimes.h"

#include <iostream>
#include <numeric>
#include <ostream>
#include <valarray>
#include <vector>

int LeetCode204CountPrimes::countPrimes(int n) {
    if (n <= 2)
        return 0;
    int sqrt=std::sqrt(n-1)+1;
    // غربال اراتوستن
    std::vector<bool> sieve(n,true);
    int currentNumber=2;
    int nextNumber=0;
    int count=n-2;
    int byProduct;
    while (currentNumber < sqrt) {
        for (int i=2,e=(n-1)/currentNumber; i<=e; i++) {
            byProduct=i*currentNumber;
            if (!sieve[byProduct])
                continue;
            sieve[i*currentNumber]=false;
            count--;
        }
        nextNumber=currentNumber;
        for (int i=currentNumber+1; i<=sqrt; i++) {
            if (sieve[i]==false)
                continue;
            nextNumber=i;
            break;
        }
        if (currentNumber == nextNumber)
            return count;
        currentNumber=nextNumber;
    }
    return count;
}

void LeetCode204CountPrimes::Run() {
    int n=10;
    std::cout << countPrimes(n) << std::endl;
}
