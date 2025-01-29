//
// Created by saeed on 1/29/25.
//

#ifndef GEEKSFORGEEKSALIENDICTIONARY_H
#define GEEKSFORGEEKSALIENDICTIONARY_H
#include <string>
#include <vector>

#include "BaseProblem.h"


class GeeksForGeeksAlienDictionary : BaseProblem{
    std::string findOrder(std::vector<std::string> dict, int k) ;
    public:
    void Run() override;
};



#endif //GEEKSFORGEEKSALIENDICTIONARY_H
