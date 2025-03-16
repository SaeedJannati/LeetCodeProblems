#include "LeetCode2594MinimumTimeToRepairCars.h"

#include <algorithm>

long long LeetCode2594MinimumTimeToRepairCars::repairCars(std::vector<int>& ranks, int cars)
{
    int max = std::numeric_limits<int>::min();
    for (auto rank : ranks)
    {
        max = std::max(rank, max);
    }
    long long end = max;
    end *= cars;
    end *= cars;
    long long begin{};
    long long mid{};
    int carsCount{};
    long long minFoundSoFar = std::numeric_limits<long long>::max();
    long long count{};
    while (begin <= end)
    {
        mid = (begin + end) / 2;
        carsCount = 0;
        for (auto rank : ranks)
        {
            count = mid / rank;
            count = sqrt(count);
            carsCount += count;
            if (carsCount >= cars)
                break;
        }
        if (carsCount >= cars)
        {
            minFoundSoFar = std::min(mid, minFoundSoFar);
            end = mid - 1;
            continue;
        }
        begin = mid + 1;
    }
    return minFoundSoFar;
}
