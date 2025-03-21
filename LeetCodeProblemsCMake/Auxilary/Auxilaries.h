//
// Created by saeed on 1/2/25.
//

#ifndef AUXILARIES_H
#define AUXILARIES_H


#include <iostream>
#include <vector>

class Auxilaries {
public:
    template<typename T>
    static void PrintVector(const std::vector<T> &vector) {
        std::cout << '[';
        for (const auto i: vector)
            std::cout << i << ",";
        std::cout << ']';
        std::cout << '\n';
    }

    template<typename T>
    static void PrintVector2D(const std::vector<std::vector<T> > &vector) {
        std::cout << '{';
        for (const auto &i: vector) {
            std::cout << '{';
            for (const auto &j: i) {
                std::cout << j << ",";
            }
            std::cout << "},";
        }
        std::cout << '}';
        std::cout << '\n';
    }

    static void ConvertToVector(std::string &str);
};


#endif //AUXILARIES_H
