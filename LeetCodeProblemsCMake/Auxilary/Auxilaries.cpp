//
// Created by saeed on 1/2/25.
//

#include "Auxilaries.h"

#include <iostream>

void Auxilaries::PrintVector(std::vector<int>& vector)
{
    for (const auto i : vector)
        std::cout << i << " ";
    std::cout << '\n';
}

