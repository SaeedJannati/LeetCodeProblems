#include "Auxilaries.h"

#include <iostream>

void Auxilaries::PrintVector(const std::vector<int>& vector)
{
    for (const auto i : vector)
        std::cout << i << " ";
    std::cout << '\n';
}

void Auxilaries::PrintVector( const std::vector<std::vector<int>>& vector)
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

void Auxilaries::ConvertToVector(std::string &str) {
    for (auto & c: str) {
        if (c == '[')
            c = '{';
        if (c == ']')
            c = '}';
    }
    std::cout << str << std::endl;
}
