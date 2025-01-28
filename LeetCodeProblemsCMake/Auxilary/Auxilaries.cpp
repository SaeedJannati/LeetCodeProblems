//
// Created by saeed on 1/2/25.
//

#include "Auxilaries.h"

#include <iostream>


void Auxilaries::ConvertToVector(std::string &str) {
    for (auto & c: str) {
        if (c == '[')
            c = '{';
        if (c == ']')
            c = '}';
    }
    std::cout << str << std::endl;
}
