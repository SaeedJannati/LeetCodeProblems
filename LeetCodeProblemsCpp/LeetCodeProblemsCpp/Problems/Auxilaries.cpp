#include "Auxilaries.h"

#include <iostream>

void Auxilaries::PrintVector(std::vector<int>& vector)
{
    for (const auto i : vector)
        std::cout << i << " ";
    std::cout << '\n';
}

void Auxilaries::PrintVector(std::vector<std::vector<int>>& vector)
{
    for (const auto& i : vector)
    {
        std::cout << "[";
        for (const auto j : i)
            std::cout << j << ",";
        std::cout << ']';
    }
    std::cout << '\n';
}
