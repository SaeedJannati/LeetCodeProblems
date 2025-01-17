//
// Created by saeed on 1/17/25.
//

#include "LeetCode2683NeighboringBitwiseXOR.h"

#include <bitset>

#include "../Auxilary/Auxilaries.h"

bool LeetCode2683NeighboringBitwiseXOR::doesValidArrayExist(std::vector<int> &derived) {
    int n = static_cast<int>(derived.size());
    std::vector<int> original(n, 0);
    int first = 0;
    for (int i = 0; i < n; i++) {
        first = first ^ derived[i];
    }
    original[0] = first;
    for (int i = 1; i < n ; i++) {
        switch (original[i - 1]) {
            case 0:
                switch (derived[i - 1]) {
                    case 0:
                        original[i] = 0;
                        break;
                    case 1:
                        original[i] = 1;
                        break;
                }
                break;
            case 1:
                switch (derived[i - 1]) {
                    case 0:
                        original[i] = 1;
                        break;
                    case 1:
                        original[i] = 0;
                        break;
                }
                break;
        }
    }
    return (original[n - 1] ^ original[0]) == derived[n - 1];
}

void LeetCode2683NeighboringBitwiseXOR::Run() {
    std::vector<int> derived = {1, 1};
   const auto result = doesValidArrayExist(derived);
    std::cout << result << std::endl;
}
