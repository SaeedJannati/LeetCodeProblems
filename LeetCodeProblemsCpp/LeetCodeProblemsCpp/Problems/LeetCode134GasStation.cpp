#include "LeetCode134GasStation.h"

#include <iostream>
#include <numeric>
#include <ostream>

void LeetCode134GasStation::Run()
{
    std::vector<int> gas = {2, 3, 4};
    std::vector<int> cost = {3, 4, 3};
    auto ouPut = canCompleteCircuit(gas, cost);
    std::cout << ouPut << '\n';
}

int LeetCode134GasStation::canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost)
{
    auto size = static_cast<int>(gas.size());
    int remaining(0);
    int currentIndex(0);
    // for bullshit testcases which are there only to make solution fail!
    int sumGas= std::accumulate(gas.begin(), gas.end(), 0);
    int sumCost= std::accumulate(cost.begin(), cost.end(), 0);
    if(sumGas<sumCost)
        return -1;
    for (auto i = 0; i < size; i++)
    {
        currentIndex = i;
        remaining = 0;
        while (true)
        {
            remaining += gas[currentIndex];

            remaining -= cost[currentIndex];
            if (remaining < 0)
            {
                if (currentIndex > i)
                    i = currentIndex;
                break;
            }
            currentIndex++;
            if (currentIndex == size)
                currentIndex = 0;
            if (currentIndex == i)
                return i;
        }
    }
    return -1;
}
